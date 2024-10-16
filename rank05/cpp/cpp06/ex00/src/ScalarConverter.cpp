#include "ScalarConverter.hpp"

// Constructeur privé (non implémenté car inutile)
ScalarConverter::ScalarConverter() {}

void ScalarConverter::convert(const std::string &literal) {
	double value;

	if (isPseudoLiteral(literal)) {
		value = getPseudoLiteralValue(literal);
	} else {
		try
		{
			value = std::stod(literal);
		}
		catch (const std::invalid_argument &)
		{
			std::cerr << "Conversion impossible: argument invalide." << std::endl;
			return;
		}
		catch (const std::out_of_range &)
		{
			std::cerr << "Conversion impossible: hors de portée." << std::endl;
			return;
		}
	}
	printChar(value);
	printInt(value);
	printFloat(value);
	printDouble(value);
}

void ScalarConverter::printChar(double value) {
    if (value < 0 || value > 255 || std::isnan(value)) {
        std::cout << "char: impossible" << std::endl;
    } else if (std::isprint(static_cast<char>(value))) {
        std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
    } else {
        std::cout << "char: Non displayable" << std::endl;
    }
}

void ScalarConverter::printInt(double value) {
	if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max() || std::isnan(value)) {
		std::cout << "int: impossible" << std::endl;
	} else {
		std::cout << "int: " << static_cast<int>(value) << std::endl;
	}
}

void ScalarConverter::printFloat(double value) {
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
}

void ScalarConverter::printDouble(double value)
{
	// std::stringstream	ss;

	// ss << value;
	std::cout << "ss : " << value << std::endl;
	std::cout << "double: " << value << std::endl;
}

bool	ScalarConverter::isPseudoLiteral(const std::string &literal)
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

double	ScalarConverter::getPseudoLiteralValue(const std::string &literal)
{
	if (literal == "nan" || literal == "nanf")
		return (std::numeric_limits<double>::quiet_NaN());
	else if (literal == "+inf" || literal == "+inff")
		return (std::numeric_limits<double>::infinity());
	else if (literal == "-inf" || literal == "-inff")
		return -(std::numeric_limits<double>::infinity());
	return (0.0);
}
