#ifndef A_MATERIA_HPP
#define A_MATERIA_HPP

#include <iostream>

class ICharacter;

class AMateria
{
protected:
	std::string _type;
public:
	AMateria();
	AMateria(std::string const & type);
	AMateria(const AMateria& b);
	virtual ~AMateria();

	std::string const & getType() const;
	AMateria& operator=(const AMateria& rhs);

	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};

#endif //A_MATERIA_HPP