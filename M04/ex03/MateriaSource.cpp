#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_sources[i] = nullptr;
}

MateriaSource::MateriaSource(const MateriaSource& b)
{
	std::cout << "MateriaSource copy constructor called" << std::endl;
	*this = b;
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		if (this->_sources[i])
			delete this->_sources[i];
}

MateriaSource& MateriaSource::operator=(const MateriaSource& rhs)
{
	for (int i = 0; i < 4; i++)
		if (this->_sources[i])
			delete this->_sources[i];
	for (int i = 0; i < 4; i++)
	{
		if (rhs._sources[i])
			this->_sources[i] = rhs._sources[i]->clone();
		else
			this->_sources[i] = nullptr;
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_sources[i] == nullptr)
		{
			this->_sources[i] = m;
			break;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_sources[i])
			if (this->_sources[i]->getType() == type)
				return (this->_sources[i]->clone());
	}
	return (0);
}