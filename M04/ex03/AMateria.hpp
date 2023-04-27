#ifndef A_MATERIA_HPP
#define A_MATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class AMateria
{
protected:
	std::string _type;
	AMateria();
public:
	AMateria(std::string const & type);
	AMateria(const AMateria& b);
	~AMateria();

	std::string const & getType() const; //Returns the materia type
	AMateria& operator=(const AMateria& rhs);

	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};

#endif //A_MATERIA_HPP