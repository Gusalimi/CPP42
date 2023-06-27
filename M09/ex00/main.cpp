#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./bitcoin [input]" << std::endl;
		return 1;
	}
	try
	{
		BitcoinExchange exchange("data.csv");
		std::ifstream file(argv[1]);
		if (!file.is_open())
			throw std::runtime_error("Could not open file");
		std::string line;
		while (std::getline(file, line))
		{
			try
			{
				std::cout << exchange.convert(line) << std::endl;
			}
			catch (std::exception &e)
			{
				std::cout << e.what() << std::endl;
			}
		}
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return 1;
	}
	return 0;
}