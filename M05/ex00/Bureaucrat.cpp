#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("noName"), _grade(150)
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name)
{
	std::cout << "Bureaucrat constructor called" << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& b)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	*this = b;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs)
{
	std::cout << "Bureaucrat copy assignment operator called" << std::endl;
	this->_grade = rhs._grade;
	return (*this);
}

const std::string Bureaucrat::getName() const { return (this->_name); }

int Bureaucrat::getGrade() const { return (this->_grade); }

void	Bureaucrat::incrementGrade()
{
	if (this->_grade > 1)
		this->_grade--;
	else
		throw Bureaucrat::GradeTooHighException();
}

void	Bureaucrat::decrementGrade()
{
	if (this->_grade < 150)
		this->_grade++;
	else
		throw Bureaucrat::GradeTooLowException();
}

std::ostream & operator<<( std::ostream & o, Bureaucrat const & rhs )
{
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
	return (o);
}