#include "Cure.hpp"

Cure::Cure()
{
	std::cout << "Cure constructor called" << std::endl;
	this->_type = "cure";
}

Cure::Cure(const Cure& b)
{
	std::cout << "Cure copy constructor called" << std::endl;
	this->_type = "cure";
}

Cure::~Cure()
{
	std::cout << "Cure destructor called" << std::endl;
}

Cure& Cure::operator=(const Cure& rhs)
{
	std::cout << "Cure copy assignment operator called" << std::endl;
	this->_type = "cure";
}

Cure* Cure::clone() const
{
	return (new Cure());
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *";
}