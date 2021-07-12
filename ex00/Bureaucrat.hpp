#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <iostream>

class Bureaucrat
{
		std::string const name;
		int	grade;
		Bureaucrat();

	public:
		Bureaucrat(std::string const &name, int grade);
		virtual ~Bureaucrat();
		Bureaucrat(const Bureaucrat& copy);
		Bureaucrat& operator=(const Bureaucrat& op);
		std::string const &getName() const;
		int getGrade() const;

};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

#endif