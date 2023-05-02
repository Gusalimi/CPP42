#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form(): _name("default"), _gradeToSign(150), _gradeToExec(150)
{
	std::cout << "Form default constructor called" << std::endl;
	this->_isSigned = false;
}

Form::Form(std::string name, int gradeToSign, int gradeToExec): _name(name), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	std::cout << "Form constructor called" << std::endl;
	if (gradeToExec < 1 || gradeToSign < 1)
		throw Form::GradeTooHighException();
	else if (gradeToExec > 150 || gradeToSign > 150)
		throw Form::GradeTooLowException();
	this->_isSigned = false;
}

Form::Form(const Form& b): _name(b._name), _gradeToSign(b._gradeToSign), _gradeToExec(b._gradeToExec)
{
	std::cout << "Form copy constructor called" << std::endl;
	*this = b;
}

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}

Form& Form::operator=(const Form& rhs)
{
	std::cout << "Form copy assignment operator called" << std::endl;
	this->_isSigned = rhs._isSigned;
	return (*this);
}

const std::string Form::getName() const { return (this->_name); }
bool Form::isSigned() const { return (this->_isSigned); }
int Form::getGradeToExecute() const { return (this->_gradeToExec); }
int Form::getGradeToSign() const { return (this->_gradeToSign); }

void Form::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() <= this->_gradeToSign)
		this->_isSigned = true;
	else
		throw Form::GradeTooLowException();
}

std::ostream & operator<<( std::ostream & o, Form const & rhs )
{
	o << rhs.getName() << ", needs grade " << rhs.getGradeToSign() << " to sign and grade " << rhs.getGradeToExecute() << " to execute " << (rhs.isSigned() ? "is" : "is not") << " signed";
	return (o);
}