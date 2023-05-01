#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

class PresidentialPardonForm: public Form
{
private:
	std::string _target;
public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string _target);
	PresidentialPardonForm(const PresidentialPardonForm& b);
	~PresidentialPardonForm();
	PresidentialPardonForm& operator=(const PresidentialPardonForm& rhs);

	void execute(Bureaucrat const & executor) const;
};

#endif /* PRESIDENTIAL_PARDON_FORM_HPP */
