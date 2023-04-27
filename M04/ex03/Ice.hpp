#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice: public AMateria
{
public:
	Ice();
	Ice(const Ice& b);
	~Ice();
	Ice& operator=(const Ice& rhs);

	Ice* clone() const;
	void use(ICharacter& target);
};

Ice::Ice(/* args */)
{
}

Ice::~Ice()
{
}

#endif //ICE_HPP