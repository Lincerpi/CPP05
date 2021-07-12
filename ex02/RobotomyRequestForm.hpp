#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <string>
#include <iostream>
#include "Form.hpp"

class RobotomyRequestForm: public Form
{
		std::string const target;
		RobotomyRequestForm();

	public:
		~RobotomyRequestForm();
		RobotomyRequestForm(std::string const target);
		RobotomyRequestForm(const RobotomyRequestForm &copy);
		RobotomyRequestForm& operator=(const RobotomyRequestForm &op);
		void execute(Bureaucrat const &executor) const;
};

#endif