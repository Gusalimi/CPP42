#include "Ice.hpp"

Ice::Ice()
{
	std::cout << "Ice constructor called" << std::endl;
	this->_type = "ice";
}

Ice::Ice(const Ice& b)
{
	std::cout << "Ice copy constructor called" << std::endl;
	this->_type = "ice";
}

Ice::~Ice()
{
	std::cout << "Ice destructor called" << std::endl;
}

Ice& Ice::operator=(const Ice& rhs)
{
	std::cout << "Ice copy assignment operator called" << std::endl;
	this->_type = "ice";
}

Ice* Ice::clone() const
{
	return (new Ice());
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *";
}