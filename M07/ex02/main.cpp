#include <iostream>
#include "Array.hpp"

int main()
{
	Array<int> a(5);
	Array<int> b(6);

	for (int i = 0; i < 5; i++)
	{
		a[i] = i;
		b[i] = i + 5;
	}
	b[5] = 10;

	std::cout << "a: ";
	for (int i = 0; i < a.size(); i++)
		std::cout << a[i] << " ";
	std::cout << std::endl;

	std::cout << "b: ";
	for (int i = 0; i < b.size(); i++)
		std::cout << b[i] << " ";
	std::cout << std::endl;

	std::cout << "a.size(): " << a.size() << std::endl;
	std::cout << "b.size(): " << b.size() << std::endl;

	std::cout << std::endl;

	Array<int> c(a);

	std::cout << "c: ";
	for (int i = 0; i < c.size(); i++)
		std::cout << c[i] << " ";
	std::cout << std::endl;

	std::cout << "c.size(): " << c.size() << std::endl;

	std::cout << std::endl;

	c = b;

	std::cout << "c: ";
	for (int i = 0; i < c.size(); i++)
		std::cout << c[i] << " ";
	std::cout << std::endl;

	std::cout << "c.size(): " << c.size() << std::endl;

	std::cout << std::endl;

	try
	{
		std::cout << "a[5]: " << a[5] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "a[5]: " << e.what() << std::endl;
	}

	try
	{
		std::cout << "a[-1]: " << a[-1] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "a[-1]: " << e.what() << std::endl;
	}

	std::cout << std::endl;

	Array<float> d(5);
	for (int i = 0; i < d.size(); i++)
		d[i] = static_cast<float>(i) + 0.5f;
	std::cout << "d: ";
	for (int i = 0; i < d.size(); i++)
		std::cout << d[i] << " ";
	std::cout << std::endl;

	return 0;
}