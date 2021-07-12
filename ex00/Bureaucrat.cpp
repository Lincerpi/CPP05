#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string const &name, int grade)
:
name(name),
grade(grade)
{
	// if (grade < 1)
	// 	throw ;
	// if (grade > 150)
	// 	throw ;
}

Bureaucrat::~Bureaucrat()
{}

Bureaucrat::Bureaucrat(const Bureaucrat& copy):
name(copy.name),
grade(copy.grade)
{
	// if (grade < 1)
	// 	throw ;
	// if (grade > 150)
	// 	throw ;
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

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return (out); 
}
