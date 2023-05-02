#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
	Intern someRandomIntern;
	Form* rrf;
	Form* ppf;
	Form* scf;
	Form* of;

	std::cout << std::endl;

	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	std::cout << std::endl;
	ppf = someRandomIntern.makeForm("presidential pardon", "Bobby");
	std::cout << std::endl;
	scf = someRandomIntern.makeForm("shrubbery creation", "Garden");
	std::cout << std::endl;
	of = someRandomIntern.makeForm("unknown", "Unknown");

	std::cout << std::endl;

	delete rrf;
	delete ppf;
	delete scf;

	std::cout << std::endl;

	return (0);
}