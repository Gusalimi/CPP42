#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"

class Bureaucrat
{
private:
	const std::string _name;
	int _grade;
public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat& b);
	~Bureaucrat();
	Bureaucrat& operator=(const Bureaucrat& rhs);

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
	int getGrade() const;
	void	incrementGrade();
	void	decrementGrade();

	void signForm(Form& form) const;
};

std::ostream & operator<<( std::ostream & o, Bureaucrat const & rhs );

#endif /* BUREAUCRAT_HPP */
