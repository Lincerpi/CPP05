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

Form* Intern::makeForm(std::string const &name, std::string target) const
{
	Form *form = nullptr;

	for (int i = 0; i < 3; i++)
	{
		if (name == type[i])
		{
			form = new RobotomyRequestForm(target); // aggiungere scelta FORM
			std::cout << "Intern creates " << *form << std::endl;
			return (form);
		}
	}
	throw FormNotExistException();
}

