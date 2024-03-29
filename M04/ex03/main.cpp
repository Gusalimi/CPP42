#include "Character.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	me->unequip(0);
	delete tmp;
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	tmp = src->createMateria("ice");
	me->equip(tmp);
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);

	me->use(7, *bob);
	me->unequip(7);

	delete bob;
	delete me;
	delete src;

	return 0;
}