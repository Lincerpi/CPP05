#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::~PresidentialPardonForm()
{}

PresidentialPardonForm::PresidentialPardonForm(std::string const target)
:
Form("PresidentialPardonForm", 25, 5),
target(target)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy)
:
Form(copy.getName(), copy.getSignedGrade(), copy.getSignedExecute()),
target(copy.target)
{}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& op)
{
	if (this == &op)
		return (*this);
	Form::operator=(op);
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	Form::execute(executor);
	std::cout << target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}


