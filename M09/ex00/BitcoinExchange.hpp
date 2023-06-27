#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

class BitcoinExchange
{
private:
	std::map<std::string, double> _prices;
	BitcoinExchange();
public:
	BitcoinExchange(std::string const &filename);
	BitcoinExchange(BitcoinExchange const &other);
	~BitcoinExchange();
	BitcoinExchange &operator=(BitcoinExchange const &other);
	double convert(std::string line) const;
};


#endif /* BITCOINEXCHANGE_HPP */
