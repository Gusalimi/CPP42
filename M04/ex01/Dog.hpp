#ifndef DOG_HPP
#define DOG_HPP

#include "Brain.hpp"
#include "Animal.hpp"

class Dog: public Animal
{
private:
	Brain* _brain;
public:
	Dog();
	Dog(const Dog& b);
	~Dog();
	Dog& operator=(const Dog& rhs);
	void makeSound() const;
};

#endif /* DOG_HPP */
