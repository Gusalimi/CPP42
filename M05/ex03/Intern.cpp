#include "Intern.hpp"

Intern::Intern() { std::cout << "Intern default constructor called" << std::endl; }

Intern::Intern(const Intern& b)
{
	(void)b;
	std::cout << "Intern copy constructor called" << std::endl;
}

Intern::~Intern() { std::cout << "Intern destructor called" << std::endl; }

Intern& Intern::operator=(const Intern& rhs)
{
	(void)rhs;
	std::cout << "Intern copy assignment operator called" << std::endl;
	return (*this);
}

Form* Intern::makeForm(std::string name, std::string target)
{
	std::string names[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
	Form *forms[3] = {new RobotomyRequestForm(target), new PresidentialPardonForm(target), new ShrubberyCreationForm(target)};
	Form *form = nullptr;
	for (int i = 0; i < 3; i++)
	{
		if (names[i] == name)
			form = forms[i];
		else
			delete forms[i];
	}
	if (form == nullptr)
		std::cout << "\033[31mInvalid form name\033[0m" << std::endl;
	else
		std::cout << "\033[32mIntern creates " << form->getName() << "\033[1;0m" << std::endl;
	return (form);
}