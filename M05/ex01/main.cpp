#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat b1("B1", 1);
	Bureaucrat b2("B2", 35);
	Bureaucrat b3("B3", 150);
	
	std::cout << std::endl;

	Form f1("F1", 120, 5);
	try
	{
		Form f2("F2", 0, 12);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Form f3("F3", 37, 151);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	std::cout << std::endl;

	std::cout << f1 << std::endl;
	try
	{
		f1.beSigned(b3);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << f1 << std::endl;
	b3.signForm(f1);
	b2.signForm(f1);
	std::cout << f1 << std::endl;
	
	std::cout << std::endl;

	return (0);
}