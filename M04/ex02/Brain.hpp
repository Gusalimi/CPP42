#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
private:
	std::string _ideas[100];
public:
	Brain();
	Brain(const Brain& b);
	~Brain();
	Brain& operator=(const Brain& rhs);
};

#endif /* BRAIN_HPP */
