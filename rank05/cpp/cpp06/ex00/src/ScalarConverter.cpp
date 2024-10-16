#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
	*this = src;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src)
{
	(void)src;
	return (*this);
}

ScalarConverter::~ScalarConverter() {}

static bool	isLiterals(const std::string &literal)
{
	const std::string pseudoLiterals[] = {
		"nan", "nanf", "+inf", 
		"-inf", "+inff", "-inff"
	};

	for (size_t i = 0; i < 6 ; i++)
	{
		if (literal == pseudoLiterals[i])
			return true;
	}
	return false;
}

static double	getPseudoLiteralValue(const std::string &literal)
{
	if (literal == "nan" || literal == "nanf")
		return (std::numeric_limits<double>::quiet_NaN());
	else if (literal == "+inf" || literal == "+inff")
		return (std::numeric_limits<double>::infinity());
	else if (literal == "-inf" || literal == "-inff")
		return -(std::numeric_limits<double>::infinity());
	return (0.0);
}

static double	getValue(const std::string &literal)
{
	double	value;

	if (isLiterals(literal))
		value = getPseudoLiteralValue(literal);
	else
		value = std::stod(literal);
	return (value);
}

static void	printChar(double value)
{
	if (value < 0 || value > 255 || std::isnan(value))
		std::cout << "char: impossible" << std::endl;
	else if (std::isprint(static_cast<char>(value)))
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
}

static void	printInt(double value) {
	if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max() || std::isnan(value)) {
		std::cout << "int: impossible" << std::endl;
	} else {
		std::cout << "int: " << static_cast<int>(value) << std::endl;
	}
}

static void	printFloat(double value) {
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
}

static void	printDouble(double value)
{
	// std::stringstream	ss;

	// ss << value;
	std::cout << "ss : " << value << std::endl;
	std::cout << "double: " << value << std::endl;
}

void	ScalarConverter::convert(const std::string &literal)
{
	double	value;

	try
	{
		if (!isLiterals(literal))
			value = std::stod(literal);
		else
			value = getPseudoLiteralValue(literal);
	}
	catch (const std::invalid_argument &e)
	{
		throw e;
	}
	catch (const std::out_of_range &e)
	{
		throw e;
	}
	printChar(value);
	printInt(value);
	printFloat(value);
	printDouble(value);
}
