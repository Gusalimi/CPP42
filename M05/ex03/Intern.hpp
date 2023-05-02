#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "Form.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
public:
	Intern();
	Intern(const Intern& b);
	~Intern();
	Intern& operator=(const Intern& rhs);

	Form *makeForm(std::string name, std::string target);
};

#endif /* INTERN_HPP */
