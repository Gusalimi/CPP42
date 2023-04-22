#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
	this->type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(const WrongAnimal& b)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = b;
}

WrongAnimal::~WrongAnimal() { std::cout << "WrongAnimal destructor called" << std::endl; }

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& rhs)
{
	std::cout << "WrongAnimal copy assignment operator called" << std::endl;
	this->type = rhs.type;
	return (*this);
}

void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal sound" << std::endl;
}

std::string WrongAnimal::getType() const { return (this->type); }