#include "Data.hpp"
#include "Serializer.hpp"
#include <iostream>

int main()
{
	Data d;
	d.i = 42;
	d.c = 'a';
	d.s = "Hello World";

	std::cout << "d.i = " << d.i << " | d.c = " << d.c << " | d.s = " << d.s << std::endl;
	std::cout << "&d: " << &d << std::endl;
	uintptr_t r1 = Serializer::serialize(&d);
	std::cout << "r1: " << r1 << std::endl;
	Data *r2 = Serializer::deserialize(r1);
	std::cout << "r2: " << r2 << std::endl;
	std::cout << "r2->i = " << r2->i << " | r2->c = " << r2->c << " | r2->s = " << r2->s << std::endl;
}