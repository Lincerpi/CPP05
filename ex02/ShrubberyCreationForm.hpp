#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <string>
#include <iostream>
#include <fstream>
#include "Form.hpp"

class ShrubberyCreationForm: public Form
{
		std::string const target;
		ShrubberyCreationForm();
		std::string tree() const;

	public:
		static std::string const &name;
		virtual ~ShrubberyCreationForm();
		ShrubberyCreationForm(std::string const &target);
		ShrubberyCreationForm(const ShrubberyCreationForm& copy);
		class TargetFileOpenException: public std::exception
		{	virtual const char* what() const throw(); };
		class WriteException: public std::exception
		{	virtual const char* what() const throw(); };
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm &op);
		void execute(Bureaucrat const &executor) const;
};

#endif