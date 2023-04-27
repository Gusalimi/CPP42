#include "AMateria.hpp"

AMateria::AMateria(std::string const & type)
{
	std::cout << "AMateria constructor called" << std::endl;
	this->_type = type;
}

AMateria::AMateria(const AMateria& b)
{
	std::cout << "AMateria copy constructor called" << std::endl;
	*this = b;
}

AMateria::~AMateria() { std::cout << "AMateria destructor called" << std::endl; }

std::string const & AMateria::getType() const { return this->_type; }

AMateria& AMateria::operator=(const AMateria& rhs)
{
	std::cout << "AMateria copy assignment operator called" << std::endl;
	this->_type = rhs._type;
}