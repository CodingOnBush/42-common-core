#include "../inc/ScalarConverter.hpp"

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
}
