#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	Animal* tab[10];
	Animal* j = new Cat();

	for (int i = 0; i < 5; i++)
		tab[i] = new Dog();
	for (int i = 5; i < 10; i++)
		tab[i] = new Cat();
	for (int i = 0; i < 10; i++)
		std::cout << "tab[" << i << "]->type = " << tab[i]->getType() << std::endl;

	std::cout << "j->type = " << j->getType() << std::endl;
	delete j;
	j = tab[2];
	std::cout << "j->type = " << j->getType() << std::endl;

	for (int i = 0; i < 10; i++)
		delete (tab[i]);

	Dog basic;
	{
		Dog tmp = basic;
	}
	Cat basic2;
	{
		Cat tmp2 = basic2;
	}


	return 0;
}