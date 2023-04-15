#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal default constructor called" << std::endl;
	this->type = "Random Animal";
}

Animal::Animal(const Animal& b)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = b;
}

Animal::~Animal() { std::cout << "Animal destructor called" << std::endl; }

Animal& Animal::operator=(const Animal& rhs)
{
	std::cout << "Animal copy assignment operator called" << std::endl;
	this->type = rhs.type;
	return (*this);
}

void Animal::makeSound() const
{
	std::cout << "Random animal makes random sound" << std::endl;
}

std::string Animal::getType() const { return (this->type); }