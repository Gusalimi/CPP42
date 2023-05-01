#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): Form("Presidential pardon", 25, 5)
{
	std::cout << "PresidentialPardonForm default constructor called" << std::endl;
	this->_target = "default";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): Form("Presidential pardon", 25, 5)
{
	std::cout << "PresidentialPardonForm constructor called" << std::endl;
	this->_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& b): Form(b)
{
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
	this->_target = b._target;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs)
{
	std::cout << "PresidentialPardonForm copy assignment operator called" << std::endl;
	this->_target = rhs._target;
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
 	if (!this->Form::isSigned() || executor.getGrade() > this->Form::getGradeToExecute())
		throw Form::GradeTooLowException();
	else
		std::cout << this->_target << " has been forgiven by Zaphod Beeblebrox" << std::endl;
}