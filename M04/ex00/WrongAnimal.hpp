#ifndef WRONG_ANIMAL_HPP
#define WRONG_ANIMAL_HPP

#include <iostream>

class WrongAnimal
{
protected:
	std::string type;
public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal& b);
	virtual ~WrongAnimal();
	WrongAnimal& operator=(const WrongAnimal& rhs);
	void makeSound() const;
	std::string getType() const;
};

#endif /* WRONG_ANIMAL_HPP */
