#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat default constructor called" << std::endl;
	this->_type = "Cat";
}

Cat::Cat(const Cat& b)
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = b;
}

Cat::~Cat() { std::cout << "Cat destructor called" << std::endl; }

Cat& Cat::operator=(const Cat& rhs)
{
	std::cout << "Cat copy assignment operator called" << std::endl;
	this->_type = rhs._type;
	return (*this);
}

void Cat::makeSound() const { std::cout << "Meow !" << std::endl; }