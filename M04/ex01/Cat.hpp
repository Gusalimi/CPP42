#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat: public Animal
{
public:
	Cat();
	Cat(const Cat& b);
	~Cat();
	Cat& operator=(const Cat& rhs);
	void makeSound() const;
};

#endif /* CAT_HPP */
