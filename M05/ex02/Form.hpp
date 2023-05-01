#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
class Bureaucrat;

class Form
{
private:
	const std::string _name;
	bool _isSigned;
	const int _gradeToSign;
	const int _gradeToExec;
public:
	Form();
	Form(std::string name, int gradeToSign, int gradeToExec);
	Form(const Form& b);
	virtual ~Form() = 0;
	Form& operator=(const Form& rhs);

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("The grade is too high");
			}
	};
	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("The grade is too low");
			}
	};

	const std::string getName() const;
	bool isSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;

	void beSigned(const Bureaucrat& b);
	virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream & operator<<( std::ostream & o, Form const & rhs );

#endif /* FORM_HPP */
