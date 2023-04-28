#include "Cure.hpp"

#include "ICharacter.hpp"

Cure::Cure(): AMateria("cure")
{
	std::cout << "Cure constructor called" << std::endl;
	this->_type = "cure";
}

Cure::Cure(const Cure& b): AMateria("cure")
{
	(void)b;
	std::cout << "Cure copy constructor called" << std::endl;
	this->_type = "cure";
}

Cure::~Cure()
{
	std::cout << "Cure destructor called" << std::endl;
}

Cure& Cure::operator=(const Cure& rhs)
{
	(void)rhs;
	std::cout << "Cure copy assignment operator called" << std::endl;
	this->_type = "cure";
	return (*this);
}

Cure* Cure::clone() const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;;
}