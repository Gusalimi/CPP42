#include <iostream>
#include <string>
#include <limits>
#include <iomanip>

int isANumber(std::string s)
{
	int i = 0;
	bool	has_point = false;
	bool	is_float = false;
	if (s[0] == '-' || s[0] == '+')
		i++;
	while (s[i])
	{
		if (!std::isdigit(s[i]))
		{
			if (s[i] == '.' && !has_point)
				has_point = true;
			else if (has_point && s[i] == 'f' && !s[i + 1])
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

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Only one argument required" << std::endl;
		return (1);
	}
	std::string s = argv[1];
	if (s.length() == 1 && !std::isdigit(s[0]))
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
	else if (isANumber(s) == 1)
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
			std::cerr << "Number too big" << std::endl;
		}
	}
	else if (isANumber(s) == 2 || s == "-inf" || s == "+inf" || s == "nan")
	{
		try
		{
			double d = std::stod(s);
			std::cout << "char: ";
			if (d < 0 || d > 127)
				std::cout << "impossible" << std::endl;
			else if (d < 32 || d == 127)
				std::cout << "Non displayable" << std::endl;
			else
				std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
			if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
				std::cout << "int: impossible" << std::endl;
			else
				std::cout << "int: " << static_cast<int>(d) << std::endl;
			if (d > std::numeric_limits<float>::max() || d < std::numeric_limits<float>::min())
				std::cout << "float: impossible" << std::endl;
			else
			{
				std::cout << "float: " << static_cast<float>(d);
				if (d - static_cast<int>(d) == 0)
					std::cout << ".0";
				std::cout << "f" << std::endl;
			}
			std::cout << "double: " << std::setprecision(std::numeric_limits<double>::digits10) << std::fixed << d;
			// if (d - static_cast<int>(d) == 0)
			// 	std::cout << ".0";
			std::cout << std::endl;
		}
		catch (const std::out_of_range& e)
		{
			std::cerr << "Number too big" << std::endl;
		}
	}
	else if (isANumber(s) == 3 || s == "-inff" || s == "+inff" || s == "nanf")
		std::cout << "float" << std::endl;
	else
		std::cerr << "Unrecognised format" << std::endl;
}