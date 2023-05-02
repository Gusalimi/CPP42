#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): Form("robotomy request", 72, 45)
{
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
	this->_target = "default";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): Form("robotomy request", 72, 45)
{
	std::cout << "RobotomyRequestForm constructor called" << std::endl;
	this->_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& b): Form(b)
{
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
	this->_target = b._target;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs)
{
	std::cout << "RobotomyRequestForm copy assignment operator called" << std::endl;
	this->_target = rhs._target;
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
 	if (executor.getGrade() > this->Form::getGradeToExecute())
		throw Form::GradeTooLowException();
	else if (!this->Form::isSigned())
		throw std::exception();
	else
	{
		std::cout << "* Drill noises *" << std::endl;
		srand (time(NULL));
		if (rand() % 10 < 5)
			std::cout << this->_target << " has successfully been robotomized" << std::endl;
		else
			std::cout << "Operation failed, " << this->_target << " couldn't be robotomized" << std::endl;
	}
}