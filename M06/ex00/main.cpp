#include <iostream>
#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Only one argument required" << std::endl;
		return (1);
	}
	ScalarConverter::convert(argv[1]);
}