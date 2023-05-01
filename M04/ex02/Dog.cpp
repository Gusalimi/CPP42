#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog default constructor called" << std::endl;
	this->_type = "Dog";
	this->_brain = new Brain();
}

Dog::Dog(const Dog& b)
{
	std::cout << "Dog copy constructor called" << std::endl;
	this->_brain = new Brain();
	*this = b;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete this->_brain;
}

Dog& Dog::operator=(const Dog& rhs)
{
	std::cout << "Dog copy assignment operator called" << std::endl;
	this->_type = rhs._type;
	*(this->_brain) = *(rhs._brain);
	return (*this);
}

void Dog::makeSound() const { std::cout << "Woof !" << std::endl; }