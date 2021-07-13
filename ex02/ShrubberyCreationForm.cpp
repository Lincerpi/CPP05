#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

std::string const &ShrubberyCreationForm::name = std::string("Shrubbery Creation");

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target)
:
Form(ShrubberyCreationForm::name, 145, 137),
target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy)
:
Form(copy.getName(), copy.getSignedExecute(), copy.getSignedGrade()),
target(copy.target)
{}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &op)
{
	if (this == &op)
		return (*this);
	Form::operator=(op);
	return (*this);
}

const char* ShrubberyCreationForm::TargetFileOpenException::what() const throw()
{	return ("Error ShrubberyCreationForm: Openn File Exception!"); }

const char* ShrubberyCreationForm::WriteException::what() const throw()
{	return ("Error ShrubberyCreationForm: Write Exception!"); }

std::string ShrubberyCreationForm::tree() const
{
	return ("Albero in ASCII");
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	Form::execute(executor);
	std::string const shrubName = (target + "_shrubbery");
	std::ofstream outfile(shrubName, std::ios::out | std::ios::app);

	if (!outfile.is_open() || outfile.bad())
		throw TargetFileOpenException();
	outfile << tree();
	if (outfile.bad())
	{
		outfile << std::endl;
		outfile.close();
		throw WriteException();
	}
	outfile << std::endl;
	outfile.close();
}
