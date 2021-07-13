#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::~RobotomyRequestForm()
{}

RobotomyRequestForm::RobotomyRequestForm(std::string const target):
Form("RobotomyRequestForm", 72, 45),
target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy):
Form(copy.getName(), copy.getSignedGrade(), copy.getSignedExecute()),
target(copy.target)
{}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &op)
{
	if (this == &op)
		return (*this);
	Form::operator=(op);
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	Form::execute(executor);
	std::cout << "DRIIIN ... DRIIIIIIN ... DRIIIN ..." << std::endl;
	if (rand() % 2)
		std::cout << target << " has been robotomized successfully!" << std::endl;
	else
		std::cout << target << ". Can't robotimized! Sorry!" << std::endl;
}