#ifndef A_MATERIA_HPP
#define A_MATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class AMateria
{
protected:
	std::string _type;
public:
	AMateria(std::string const & type);

//	[...]
	std::string const & getType() const; //Returns the materia type

	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};

#endif //A_MATERIA_HPP