#include "../inc/ScalarConverter.hpp"

ScalarConverter::~ScalarConverter()
{
}

static bool	isChar(const std::string &str)
{
	if (str.length() == 1 && !isdigit(str[0]))
		return true;
	return false;
}

static bool	isInt(const std::string &str)
{
	if (str.length() == 1 && !isdigit(str[0]))
		return false;
	for (size_t i = 0; i < str.length(); i++)
	{
		if (i == 0 && (str[i] == '-' || str[i] == '+'))
			continue;
		if (!isdigit(str[i]))
			return false;
	}
	return true;
}

void ScalarConverter::convert(const std::string &str)
{
	std::cout << "char: ";
	if (isChar(str))
	{
		char c = str[0];
		if (isprint(c))
			std::cout << "'" << c << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	}
	else if (isInt(str))
	{
		int i = std::stoi(str);
		if (i >= 32 && i <= 126)
			std::cout << "'" << static_cast<char>(i) << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	}
	else
		std::cout << "impossible" << std::endl;

	std::cout << "int: ";
	try
	{
		int i = std::stoi(str);
		std::cout << i << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "impossible" << std::endl;
	}

	std::cout << "float: ";
	try
	{
		float f = std::stof(str);
		std::cout << f << "f" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "impossible" << std::endl;
	}

	std::cout << "double: ";
	try
	{
		double d = std::stod(str);
		std::cout << d << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "impossible" << std::endl;
	}
}
