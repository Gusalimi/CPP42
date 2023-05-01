#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	PresidentialPardonForm ppf1("Billy");

	ppf1.beSigned(Bureaucrat("Roger", 1));
	ppf1.execute(Bureaucrat("Bob", 3));

	return (0);
}