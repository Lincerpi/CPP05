#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include <string>
#include <iostream>
#include "Form.hpp"

class PresidentialPardonForm: public Form
{
		std::string const target;
		PresidentialPardonForm();

	public:
		static std::string const &name;
		virtual ~PresidentialPardonForm();
		PresidentialPardonForm(std::string const target);
		PresidentialPardonForm(const PresidentialPardonForm& copy);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& op);
		void execute(Bureaucrat const &executor) const;
};

#endif