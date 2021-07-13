#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string const &name, int grade)
:
name(name),
grade(grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::~Bureaucrat()
{}

Bureaucrat::Bureaucrat(const Bureaucrat& copy):
name(copy.name),
grade(copy.grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& op)
{
	if (this == &op)
		return (*this);
	grade = op.grade;
	return (*this);
}

std::string const &Bureaucrat::getName() const
{
	return (name);
}

int Bureaucrat::getGrade() const
{
	return (grade);
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat Grade Too High!!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat Grade Too Low!!");
}

void Bureaucrat::incrementGrade()
{
	grade--;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decrementGrade()
{
	grade++;
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

void Bureaucrat::signForm(Form& form) const
{
	if (form.getIsSigned())
		std::cout << getName() << " cannot sign " << form << " because form already signed!" << std::endl;
	else if (getGrade() > form.getSignedGrade())
		std::cout << getName() << " cannot sign " << form << " because it's grade is too low!" << std::endl;
	else
		std::cout << getName() << " sign " << form << "!" << std::endl;
	form.isSigned = true;
}

void Bureaucrat::executeForm(Form const &form)
{
	if (!form.getIsSigned())
	{
		std::cout << *this << " cannot execute " << form << " because the form is unsigned." << std::endl;
	}
	else if (form.getSignedExecute() < grade)
	{
		std::cout << *this << " cannot execute " << form << " because it's grade is too low." << std::endl;
	}
	else
	{
		std::cout << *this << " executes " << form << std::endl;
	}
	form.execute(*this);
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return (out); 
}
