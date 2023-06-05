#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <limits>
#include <iomanip>

class ScalarConverter
{
public:
	static void convert(std::string s);
private:
	ScalarConverter();
	ScalarConverter(ScalarConverter const &other);
	~ScalarConverter();
	ScalarConverter &operator=(ScalarConverter const &other);
	static int isANumber(std::string s);
	static void fromChar(std::string s);
	static void fromInt(std::string s);
	static void fromDouble(std::string s);
	static void fromFloat(std::string s);
};

#endif /* SCALARCONVERTER_HPP */
