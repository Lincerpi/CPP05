#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat b1("Paolo", 5);
	Bureaucrat b2("Luca", 0);
	Bureaucrat b3("Francesco", 151);
	Bureaucrat b4("GianFrancioschio", 150);
	Bureaucrat b5("Pasqualino", 1);

	std::cout << b1 << std::endl;
	std::cout << b2 << std::endl;
	std::cout << b3 << std::endl;
	std::cout << b4 << std::endl;
	std::cout << b5 << std::endl;
	
	return (0);
}