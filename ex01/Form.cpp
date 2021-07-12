#include "Form.hpp"

Form::~Form()
{}

Form::Form(std::string const &name, int const signedGrade, int const signedExecute)
:
name(name),
signedGrade(signedGrade),
signedExecute(signedExecute)
{
	isSigned = false;
	if (signedGrade < 1 || signedExecute < 1)
		throw Form::GradeTooHighException();
	if (signedGrade > 150 || signedExecute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& copy)
:
name(copy.name),
signedGrade(copy.signedGrade),
signedExecute(copy.signedExecute)
{
	isSigned = copy.isSigned;
	if (signedGrade < 1 || signedExecute < 1)
		throw Form::GradeTooHighException();
	if (signedGrade > 150 || signedExecute > 150)
		throw Form::GradeTooLowException();
}

Form& Form::operator=(const Form& op)
{
	if (this == &op)
		return (*this);
	isSigned = op.isSigned;
	return (*this);
}

std::string const &Form::getName() const
{	return (name); }

int Form::getSignedGrade() const
{	return (signedGrade); }

int Form::getSignedExecute() const
{	return (signedExecute); }

bool Form::getIsSigned() const
{	return (isSigned); }

const char* Form::GradeTooHighException::what() const throw()
{	return ("Error Form: Grade is Too High!"); }

const char* Form::GradeTooLowException::what() const throw()
{	return ("Error Form: Grade is Too Low!"); }

const char* Form::AlreadySignedException::what() const throw()
{	return ("Error Form: Form already signed!"); }

void Form::beSigned(Bureaucrat const &bureaucrat)
{
	if (isSigned)
		throw Form::AlreadySignedException();
	else if (bureaucrat.getGrade() > signedGrade)
		throw Form::GradeTooLowException();
	isSigned = true;
}

std::ostream& operator<<(std::ostream& out, const Form& form)
{
	out << form.getName() << (form.getIsSigned() ? " Signed" : " Unnsigned")
	<< "[Signed grade: " << form.getSignedGrade() << "; Signed execute: " << form.getSignedExecute() << "]";
	return (out);
}