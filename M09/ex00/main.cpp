#include "BitcoinExchange.hpp"
#include <iostream>

bool isValidDateFormat(std::string date)
{
	if (date.length() != 10)
		return false;
	if (date[4] != '-' || date[7] != '-' || !(isdigit(date[0]) && isdigit(date[1]) && isdigit(date[2]) && isdigit(date[3]) && isdigit(date[5]) && isdigit(date[6])&& isdigit(date[8]) && isdigit(date[9])))
		return false;
	return true;
}

int main(int argc, char **argv)
{
	try {
		BitcoinExchange exchange("data.csv");
		std::ifstream file(argv[1]);
		std::string ignore;
		std::string line;
		std::string date;
		std::string value;
		double value_d;
		double convert;

		if (argc != 2)
		{
			std::cout << "Usage: ./bitcoin [input]" << std::endl;
			return (1);
		}

		if (!file.is_open())
			throw std::runtime_error("Could not open file");
		std::getline(file, line);
		while (std::getline(file, line))
		{
			if (line.empty())
				continue ;
			std::stringstream ss(line);
			if (!std::getline(ss, date, ' '))
			{
				std::cout << "Error: Bad input => " << line << std::endl;
				continue ;
			}
			if (!isValidDateFormat(date) || std::stoi(date.substr(5, 2)) > 12 || std::stoi(date.substr(8, 2)) > 31)
			{
				std::cout << "Error: invalid date => " << date << std::endl;
				continue ;
			}
			std::getline(ss, ignore, '|');
			std::getline(ss, ignore, ' ');
			if (!std::getline(ss, value))
			{
				std::cout << "Error: Bad input => " << line << std::endl;
				continue ;
			}
			try
			{
				value_d = std::stod(value);
			}
			catch (std::exception &e)
			{
				std::cout << "Error: too large a number." << std::endl;
				continue ;
			}
			if (value_d < 0)
			{
				std::cout << "Error: negative number." << std::endl;
				continue ;
			}
			if (value_d > 1000)
			{
				std::cout << "Error: too large a number." << std::endl;
				continue ;
			}
			try {
				convert = exchange.convert(date, value_d);
			} catch (std::exception &e) {
				std::cout << "Error: " << e.what() << std::endl;
				continue ;
			}
			std::cout << date << " => " << value << " = " << exchange.convert(date, std::stod(value)) << std::endl;
		}
		return 0;
	} catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
		return (1);
	}
}