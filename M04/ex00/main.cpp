#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	delete i;
	i = j;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	meta->makeSound();
	delete meta;
	delete j;

	const WrongAnimal* wa = new WrongAnimal();
	const WrongAnimal* k = new WrongCat();
	wa->makeSound();
	k->makeSound();
	delete wa;
	delete k;
	WrongCat a;
	a.makeSound();

	return 0;
}