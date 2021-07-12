#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include <iostream>

class Form;
#include "Bureaucrat.hpp"

class Form
{
		std::string const &name;
		int const signedGrade;
		int const signedExecute;
		bool	isSigned;
		Form();

	public:
		~Form();
		Form(std::string const &name, int const signedGrade, int const signedExecute);
		Form(const Form& copy);
		Form& operator=(const Form& op);
		std::string const &getName() const;
		int getSignedGrade() const;
		int getSignedExecute() const;
		bool getIsSigned() const;
		class GradeTooHighException: public std::exception
		{	virtual const char* what() const throw(); };
		class GradeTooLowException: public std::exception
		{	virtual const char* what() const throw(); };
		class AlreadySignedException: public std::exception
		{	virtual const char* what() const throw(); };
		void beSigned(Bureaucrat const &bureaucrat);
};

std::ostream& operator<<(std::ostream& out, const Form& form);

#endif