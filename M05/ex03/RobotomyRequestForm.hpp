#ifndef ROBOTOMY_REQUEST_HPP
#define ROBOTOMY_REQUEST_HPP

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

class RobotomyRequestForm: public Form
{
private:
	std::string _target;
public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string _target);
	RobotomyRequestForm(const RobotomyRequestForm& b);
	~RobotomyRequestForm();
	RobotomyRequestForm& operator=(const RobotomyRequestForm& rhs);

	void execute(Bureaucrat const & executor) const;
};

#endif /* ROBOTOMY_REQUEST_HPP */
