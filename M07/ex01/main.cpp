#include <iostream>
#include "iter.hpp"

template<typename T>
void print_elem(T const &elem)
{
	std::cout << elem << std::endl;
}

int main(void)
{
	int array[] = { 1, 2, 3, 4, 5 };
	std::string array2[] = { "Hello", "World", "!" };

	iter<int>(array, 5, print_elem<int>);

	std::cout << std::endl;

	iter<std::string>(array2, 3, print_elem<std::string>);

	return 0;
}