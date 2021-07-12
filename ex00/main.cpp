#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

int main()
{
	try{
		Bureaucrat b1("Paolo", 5);
		std::cout << b1 << std::endl;
		b1.incrementGrade();
		std::cout << b1 << std::endl;
		b1.decrementGrade();
		std::cout << b1 << std::endl;

	}
	catch(std::exception &e){
		std::cerr << e.what() << std::endl;
	}

	try{
		Bureaucrat b2("Luca", 0);
		std::cout << b2 << std::endl;
	}
	catch(std::exception &e){
		std::cerr << e.what() << std::endl;
	}

	try{
		Bureaucrat b3("Francesco", 151);
		std::cout << b3 << std::endl;
	}
	catch(std::exception &e){
		std::cerr << e.what() << std::endl;
	}

	try{	
		Bureaucrat b4("GianFrancioschio", 150);
		std::cout << b4 << std::endl;
		b4.decrementGrade();
	}
	catch(std::exception &e){
		std::cerr << e.what() << std::endl;
	}

	try{
		Bureaucrat b5("Pasqualino", 1);
		std::cout << b5 << std::endl;
		b5.incrementGrade();
	}
	catch(std::exception &e){
		std::cerr << e.what() << std::endl;
	}
	
	return (0);
}