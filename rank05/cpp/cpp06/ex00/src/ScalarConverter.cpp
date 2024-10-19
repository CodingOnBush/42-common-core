#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
	(void)src;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src)
{
	(void)src;
	return (*this);
}
ScalarConverter::~ScalarConverter() {}

void ScalarConverter::printChar(const std::string &str)
{
	std::stringstream	ss(str);
	int 				i;
	char 				c;

	ss >> i;
	if (ss.fail() || i < 0 || i > 127)
	{
		std::cout << "char: impossible\n";
		return ;
	}
	c = static_cast<char>(i);
	if (!std::isprint(c))
		std::cout << "char: Non displayable\n";
	else
		std::cout << "char: '" << c << "'" << std::endl;
}

static int	strToInt(const std::string &str)
{
	int i;
	std::stringstream ss(str);

	if (ss >> i)
		return (i);
	return (0);
}

static float	strToFloat(const std::string &str)
{
	float f;
	std::stringstream ss(str);

	if (ss >> f)
		return (f);
	return (0);
}

static double	strToDouble(const std::string &str)
{
	double d;
	std::stringstream ss(str);

	if (ss >> d)
		return (d);
	return (0);
}

void ScalarConverter::printInt(const std::string &str)
{
	int i;
	std::stringstream ss(str);

	if (ss >> i)
	{
		// i = strToInt(str);
		std::cout << "int: " << i << std::endl;
	}
	else
		std::cout << "int: impossible\n";
}

void ScalarConverter::printFloat(const std::string &str)
{
	std::stringstream	ss(str);
	float				f;
	
	if (ss >> f)
	{
		if (f - strToInt(str) == 0)
			std::cout << "float: " << f << ".0f" << std::endl;
		else
			std::cout << "float: " << f << "f" << std::endl;
	}
	else
		std::cout << "float:  impossible\n";
}

void	ScalarConverter::printDouble(const std::string &str)
{
	std::stringstream	ss(str);
	double 				d;
	int					i;

	ss >> d;
	if (ss.fail())
	{
		std::cout << "double: impossible\n";
		return ;
	}
	// d = strToDouble(str);
	i = strToInt(str);
	if (d - i == 0)
		std::cout << "double: " << d << ".0" << std::endl;
	else
		std::cout << "double: " << d << std::endl;
}

void	ScalarConverter::printPseudoLiterals(std::string str)
{
	std::cout << "float: " << str << std::endl;
	std::cout << "double: ";
	str.erase(str.size() - 1);
	std::cout << str << std::endl;	


	
	// {
	// 	std::cout << "float: -inff" << std::endl;
	// 	std::cout << "double: -inf" << std::endl;
	// }
	// else if (str == "nanf")
	// {
	// 	std::cout << "float: nanf" << std::endl;
	// 	std::cout << "double: nan" << std::endl;
	// }
	// else if (str == "+inff")
	// {
	// 	std::cout << "float: +inff" << std::endl;
	// 	std::cout << "double: +inf" << std::endl;
	// }
}

bool	ScalarConverter::isPseudoLiterals(const std::string &str)
{
	const std::string	pseudo[3] = {
		"-inff", "+inff", "nanf"};

	for (int i = 0; i < 3; i++)
	{
		if (str == pseudo[i])
			return (true);
	}
	return (false);
}

void ScalarConverter::convert(std::string str)
{
	std::stringstream	ss(str);
	double				value;

	ss >> value;
	if (str.empty() || ss.fail() || ss.eof())
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: impossible\n";
		std::cout << "double: impossible\n";
		return ;
	}
	printChar(str);
	printInt(str);
	if (isPseudoLiterals(str))
		printPseudoLiterals(str);
	else
	{
		if (str[str.size() - 1] == 'f')
			str.erase(str.size() - 1);
		printFloat(str);
		printDouble(str);
	}
}
