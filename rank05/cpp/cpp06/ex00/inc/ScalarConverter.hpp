#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include <cmath>
#include <iomanip>
#include <cctype>// isprint

class ScalarConverter
{
	private:
		ScalarConverter();										// Default constructor
		ScalarConverter(const ScalarConverter &src);			// Copy constructor
		ScalarConverter &operator=(const ScalarConverter &src);	// Assignment operator
		~ScalarConverter();										// Destructor

		static void	printChar(const std::string &str);
		static void	printInt(const std::string &str);
		static void	printFloat(const std::string &str);
		static void	printDouble(const std::string &str);
		static void	printPseudoLiterals(std::string str);
		static bool	isPseudoLiterals(const std::string &str);

	public:
		static void	convert(std::string	str);

};

#endif