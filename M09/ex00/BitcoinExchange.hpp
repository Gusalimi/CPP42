#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

class BitcoinExchange
{
	private:
		std::map<std::string, double> _database;

		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
	public:
		BitcoinExchange(std::string filename);
		~BitcoinExchange();
		double convert(std::string date, double amount);
};


#endif /* BITCOINEXCHANGE_HPP */
