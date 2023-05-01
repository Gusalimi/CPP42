#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	PresidentialPardonForm ppf("Billy");
	RobotomyRequestForm rrf("Bob");
	ShrubberyCreationForm scf("Garden");

	Bureaucrat b1("B1", 1);
	Bureaucrat b2("B2", 130);
	Bureaucrat b3("B3", 40);

	std::cout << std::endl;

	b2.executeForm(rrf);
	b1.signForm(rrf);
	b2.executeForm(rrf);
	b3.executeForm(rrf);

	std::cout << std::endl;

	b1.signForm(ppf);
	try
	{
		scf.execute(b1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		ppf.execute(b2);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	
	b1.signForm(scf);
	b1.executeForm(scf);
	b1.executeForm(ppf);

	std::cout << std::endl;

	return (0);
}