#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(std::string const &filename)
{
	std::ifstream file(filename);
	if (!file.is_open())
		throw std::runtime_error("Could not open file");
	std::string line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		std::stringstream ss(line);
		std::string date;
		std::string price;
		std::getline(ss, date, ',');
		std::getline(ss, price);
		_prices[date] = std::stod(price);
	}
	file.close();
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &other)
{
	*this = other;
}

BitcoinExchange::~BitcoinExchange() {}
BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &other)
{
	_prices = other._prices;
	return *this;
}

double BitcoinExchange::convert(std::string line) const
{
	/* TODO:
	Each line in this file must use the following format: "date | value".
	• A valid date will always be in the following format: Year-Month-Day.
	• A valid value must be either a float or a positive integer between 0 and 1000.
	If the date used in the input does not exist in your DB then you must use the closest date contained in your DB. Be careful to use the lower date and not the upper one.
	You have to use the c++98 standard for this exercise.
	*/
	std::stringstream ss(line);
	std::string date;
	std::string value;
	std::getline(ss, date, '|');
	std::getline(ss, value);
	if (date.empty() || value.empty())
		throw std::runtime_error("Invalid input1");
	if (_prices.find(date) == _prices.end())
	{
		std::map<std::string, double>::const_iterator it = _prices.lower_bound(date);
		if (it == _prices.begin())
			throw std::runtime_error("Invalid input2");
		it--;
		if (std::stod(value) < 0)
			throw std::runtime_error("Error: not a positive number.");
		else if (std::stod(value) > 1000)
			throw std::runtime_error("Error: too large a number.");
		return std::stod(value) * it->second;
	}
	else
	{
		if (std::stod(value) < 0)
			throw std::runtime_error("Error: not a positive number.");
		else if (std::stod(value) > 1000)
			throw std::runtime_error("Error: too large a number.");
		return std::stod(value) * _prices.at(date);
	}
}