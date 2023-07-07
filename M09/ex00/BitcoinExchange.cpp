#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &b) { (void)b; }
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs) { (void)rhs; return (*this); }
BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(std::string filename)
{
	std::ifstream file(filename);
	std::string line;
	std::string date;
	std::string value;

	if (!file.is_open())
		throw std::runtime_error("Could not open file");
	std::getline(file, line);
	while (std::getline(file, line))
	{
		std::stringstream ss(line);
		std::getline(ss, date, ',');
		std::getline(ss, value);
		_database[date] = std::stod(value);
	}
}

double BitcoinExchange::convert(std::string date, double amount)
{
	std::map<std::string, double>::iterator it = _database.find(date);
	if (it == _database.end())
	{
		std::map<std::string, double>::iterator it2 = _database.begin();
		while (it2 != _database.end() && it2->first < date)
			it2++;
		if (it2 == _database.begin())
			throw std::runtime_error("No data for this date");
		it = --it2;
	}
	return (amount * it->second);
}