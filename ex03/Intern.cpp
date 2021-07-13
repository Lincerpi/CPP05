#include "Intern.hpp"

Intern::Intern()
{
	type[0] = "Shrubbery Creation";
	type[1] = "Robotomy Request";
	type[2] = "Presidential Pardon";
}

Intern::~Intern()
{}

Intern::Intern(const Intern& copy)
{
	for (int i = 0; i < 3; i++)
		type[i] = copy.type[i];
}

Intern& Intern::operator=(const Intern &op)
{
	if (this == &op)
		return (*this);
	for (int i = 0; i < 3; i++)
		type[i] = op.type[i];
	return (*this);
}

const char* Intern::FormNotExistException::what() const throw()
{	return ("Error Form: Form not exist!"); }

Form* Intern::createForm(std::string target, int i) const
{
	Form *form[3];
	Form *tmp;

	form[0] = new ShrubberyCreationForm(target);
	form[1] = new RobotomyRequestForm(target);
	form[2] = new PresidentialPardonForm(target); 
	tmp = form[i];
	for (int i = 0; i < 3; i++)
		delete form[i];
	
	return (tmp);
}

Form* Intern::makeForm(std::string const &name, std::string target) const
{
	Form *form = nullptr;

	for (int i = 0; i < 3; i++)
	{
		if (name == type[i])
		{
			form = createForm(target, i);
			std::cout << "Intern creates " << *form << std::endl;
			return (form);
		}
	}
	throw FormNotExistException();
}

