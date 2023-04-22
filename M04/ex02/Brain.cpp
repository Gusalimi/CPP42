#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain Default constructor called" << std::endl;
}

Brain::Brain(const Brain& b)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = b;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain& Brain::operator=(const Brain& rhs)
{
	std::cout << "Brain copy assignment operator called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = rhs._ideas[i];
	return (*this);
}