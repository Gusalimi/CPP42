#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat b1("B1", 1);
	Bureaucrat b2("B2", 35);
	Bureaucrat b3("B3", 150);
	try
	{
		Bureaucrat b4("B4", 0);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat b5("B5", 151);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	std::cout << std::endl;

	std::cout << b1 << std::endl;
	try
	{
		b1.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << b1 << std::endl;

	std::cout << std::endl;

	std::cout << b2 << std::endl;
	b2.decrementGrade();
	std::cout << b2 << std::endl;
	b2.incrementGrade();
	b2.incrementGrade();
	std::cout << b2 << std::endl;

	std::cout << std::endl;

	std::cout << b3 << std::endl;
	try
	{
		b3.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << b3 << std::endl;

	return (0);
}