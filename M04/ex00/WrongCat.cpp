#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "WrongCat default constructor called" << std::endl;
	this->_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& b)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = b;
}

WrongCat::~WrongCat() { std::cout << "WrongCat destructor called" << std::endl; }

WrongCat& WrongCat::operator=(const WrongCat& rhs)
{
	std::cout << "WrongCat copy assignment operator called" << std::endl;
	this->_type = rhs._type;
	return (*this);
}