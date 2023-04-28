#include "Ice.hpp"

#include "ICharacter.hpp"

Ice::Ice(): AMateria("ice")
{
	std::cout << "Ice constructor called" << std::endl;
	this->_type = "ice";
}

Ice::Ice(const Ice& b): AMateria("ice")
{
	(void)b;
	std::cout << "Ice copy constructor called" << std::endl;
	this->_type = "ice";
}

Ice::~Ice()
{
	std::cout << "Ice destructor called" << std::endl;
}

Ice& Ice::operator=(const Ice& rhs)
{
	(void)rhs;
	std::cout << "Ice copy assignment operator called" << std::endl;
	this->_type = "ice";
	return (*this);
}

Ice* Ice::clone() const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}