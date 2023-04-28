#ifndef MATERIA_SOURCE_HPP
#define MATERIA_SOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
public:
	MateriaSource();
	MateriaSource(const MateriaSource& b);
	~MateriaSource();
	MateriaSource& operator=(const MateriaSource& rhs);

	void learnMateria(AMateria*);
	AMateria* createMateria(std::string const & type);
};


#endif //MATERIA_SOURCE_HPP