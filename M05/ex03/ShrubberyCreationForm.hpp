#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP

#include <iostream>
#include <fstream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

class ShrubberyCreationForm: public Form
{
private:
	std::string _target;
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string _target);
	ShrubberyCreationForm(const ShrubberyCreationForm& b);
	~ShrubberyCreationForm();
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& rhs);

	void execute(Bureaucrat const & executor) const;
};

#endif /* SHRUBBERY_CREATION_FORM_HPP */
