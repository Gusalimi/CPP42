#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	Animal* tab[10];
	Animal* j;

	for (int i = 0; i < 5; i++)
		tab[i] = new Dog();
	for (int i = 5; i < 10; i++)
		tab[i] = new Cat();
	for (int i = 0; i < 10; i++)
		std::cout << "tab[" << i << "]->type = " << tab[i]->getType() << std::endl;

	for (int i = 0; i < 10; i++)
		delete (tab[i]);

	return 0;
}