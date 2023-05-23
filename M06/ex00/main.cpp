#include <iostream>
#include <string>
#include <limits>
#include <iomanip>

int isANumber(std::string s)
{
	int i = 0;
	bool	has_point = false;
	bool	is_float = false;
	bool	is_scientific = false;
	if (s[0] == '-' || s[0] == '+')
		i++;
	while (s[i])
	{
		if (!std::isdigit(s[i]))
		{
			if (s[i] == '.' && !has_point)
				has_point = true;
			else if (has_point && std::tolower(s[i]) == 'e' && !is_scientific)
				is_scientific = true;
			else if (has_point && std::tolower(s[i]) == 'f' && !s[i + 1])
				is_float = true;
			else
				return (0);
		}
		i++;
	}
	if (!has_point)
		return (1);
	else if (!is_float)
		return (2);
	else
		return (3);
}

void fromChar(std::string s)
{
	char c = s[0];
	if (c < 32 || c == 127)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << c  << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void fromInt(std::string s)
{
	try
	{
		int i = std::stoi(s);
		std::cout << "char: ";
		if (i < 0 || i > 127)
			std::cout << "impossible" << std::endl;
		else if (i < 32 || i == 127)
			std::cout << "Non displayable" << std::endl;
		else
			std::cout << "'" << static_cast<char>(i) << "'" << std::endl;
		std::cout << "int: " << i << std::endl;
		std::cout << "float: " << i << ".0f" << std::endl;
		std::cout << "double: " << i << ".0" << std::endl;
	}
	catch (const std::out_of_range& e)
	{
		std::cerr << "Number out of range" << std::endl;
	}
}

void fromDouble(std::string s)
{
	try
	{
		double d = std::stod(s);
		std::cout << "char: ";
		if (d < 0 || d > 127 || s == "nan")
			std::cout << "impossible" << std::endl;
		else if (d < 32 || d == 127)
			std::cout << "Non displayable" << std::endl;
		else
			std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
		try
		{
			int i = std::stoi(s);
			std::cout << "int: " << i << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << "int: impossible" << std::endl;
		}
		try
		{
			float f = std::stof(s);
			std::cout << "float: ";
			if (s == "+inf")
				std::cout << "+";
			std::cout << f;
			if (f - static_cast<int>(f) == 0)
				std::cout << ".0";
			std::cout << "f" << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << "float: impossible" << std::endl;
		}
		std::cout << "double: ";
		if (s == "+inf")
			std::cout << "+";
		std::cout << d;
		if (d - static_cast<int>(d) == 0)
			std::cout << ".0";
		std::cout << std::endl;
	}
	catch (const std::out_of_range& e)
	{
		std::cerr << "Number out of range" << std::endl;
	}
}

void fromFloat(std::string s)
{
	try
	{
		float f = std::stof(s);
		std::cout << "char: ";
		if (f < 0 || f > 127 || s == "nanf")
			std::cout << "impossible" << std::endl;
		else if (f < 32 || f == 127)
			std::cout << "Non displayable" << std::endl;
		else
			std::cout << "'" << static_cast<char>(f) << "'" << std::endl;
		try
		{
			int i = std::stoi(s);
			std::cout << "int: " << i << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << "int: impossible" << std::endl;
		}
		std::cout << "float: ";
		if (s == "+inff")
			std::cout << "+";
		std::cout << f;
		if (f - static_cast<int>(f) == 0)
			std::cout << ".0";
		std::cout << "f" << std::endl;
		std::cout << "double: ";
		if (s == "+inff")
			std::cout << "+";
		std::cout << static_cast<double>(f);
		if (f - static_cast<int>(f) == 0)
			std::cout << ".0";
		std::cout << std::endl;
	}
	catch (const std::out_of_range& e)
	{
		std::cerr << "Number out of range" << std::endl;
	}
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Only one argument required" << std::endl;
		return (1);
	}
	std::string s = argv[1];
	if (s.length() == 1 && !std::isdigit(s[0]))
		fromChar(s);
	else if (isANumber(s) == 1)
		fromInt(s);
	else if (isANumber(s) == 2 || s == "-inf" || s == "+inf" || s == "nan")
		fromDouble(s);
	else if (isANumber(s) == 3 || s == "-inff" || s == "+inff" || s == "nanf")
		fromFloat(s);
	else
		std::cerr << "Unrecognised format" << std::endl;
}