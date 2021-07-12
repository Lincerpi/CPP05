#include <string>
#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat bureaucrat("Lillo", 100);
	std::cout << bureaucrat << std::endl;

	Form form1("Pagine Gialle", 100, 50);
	std::cout << form1 << std::endl;
	form1.beSigned(bureaucrat);
	std::cout << form1 << std::endl;
	try
	{
		bureaucrat.signForm(form1);
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "---" << std::endl;

	Form form2("Rimborso Spese", 99, 50);
	std::cout << form2 << std::endl;
	try
	{
		bureaucrat.signForm(form2);
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << form2 << std::endl;

	std::cout << "---" << std::endl;

	Form form3("Assegno", 101, 50);
	std::cout << form3 << std::endl;
	bureaucrat.signForm(form3);
	std::cout << form3 << std::endl;
	try
	{
		bureaucrat.signForm(form3);
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << form3 << std::endl;

	std::cout << "---" << std::endl;

	try
	{
		Form formException("Diario", 99, 50);
		std::cout << formException << std::endl;
		formException.beSigned(bureaucrat);
		std::cout << formException << std::endl;
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "---" << std::endl;

	try
	{
		Form formException("Annuario", 1000, 50);
		std::cout << formException << std::endl;
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "---" << std::endl;

	try
	{
		Form formException("Annuario", 0, 50);
		std::cout << formException << std::endl;
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "---" << std::endl;

	try
	{
		Form formException("Annuario", 100, 1000);
		std::cout << formException << std::endl;
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "---" << std::endl;

	try
	{
		Form formException("Annuario", 100, 0);
		std::cout << formException << std::endl;
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	return (0);
}