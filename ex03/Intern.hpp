#ifndef INTERN_HPP
# define INTERN_HPP

#include <string>
#include <iostream>

class Inter;
#include "Form.hpp"
#include "RobotomyRequestForm.hpp"
class Intern
{	
		std::string type[3];

	public:
		Intern();
		~Intern();
		Intern(const Intern& copy);
		Intern& operator=(const Intern& op);
		class FormNotExistException: public std::exception
		{	virtual const char* what() const throw(); };
		Form* makeForm(std::string const &name, std::string target) const;
};

#endif