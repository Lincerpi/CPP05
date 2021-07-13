#include <string>
#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
	Intern someIntern;
	Form *form;

	form = someIntern.makeForm("Robotomy Request", "Robot");
	std::cout << " --- " << std::endl;
	
	form = someIntern.makeForm("Presidential Pardon", "Presidential");
	std::cout << " --- " << std::endl;
	try {
		form = someIntern.makeForm("Wrong Form Type", "Bad");
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	return (0);
}