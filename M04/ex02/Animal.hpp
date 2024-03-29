#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
protected:
	std::string _type;
public:
	Animal();
	Animal(const Animal& b);
	virtual ~Animal() = 0;
	Animal& operator=(const Animal& rhs);
	virtual void makeSound() const;
	std::string getType() const;
};


#endif /* ANIMAL_HPP */
