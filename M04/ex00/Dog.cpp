#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog default constructor called" << std::endl;
	this->_type = "Dog";
}

Dog::Dog(const Dog& b)
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = b;
}

Dog::~Dog() { std::cout << "Dog destructor called" << std::endl; }

Dog& Dog::operator=(const Dog& rhs)
{
	std::cout << "Dog copy assignment operator called" << std::endl;
	this->_type = rhs._type;
	return (*this);
}

void Dog::makeSound() const { std::cout << "Woof !" << std::endl; }