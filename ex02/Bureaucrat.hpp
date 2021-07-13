#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <iostream>

class Bureaucrat;
#include "Form.hpp"

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
		class GradeTooHighException: public std::exception
		{
			virtual const char* what() const throw();
		};
		class GradeTooLowException: public std::exception
		{
			virtual const char* what() const throw();
		};
		void incrementGrade();
		void decrementGrade();
		void signForm(Form& form) const;
		void executeForm(Form const & form);
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

#endif