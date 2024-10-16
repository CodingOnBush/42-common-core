#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include <cmath>
#include <iomanip>

class ScalarConverter
{
	private:
		ScalarConverter();										// Default constructor
		ScalarConverter	(const ScalarConverter &src);			// Copy constructor
		ScalarConverter &operator=(const ScalarConverter &src);	// Assignment operator
		~ScalarConverter();										// Destructor

	    static void 	printChar(double value);
	    static void 	printInt(double value);
	    static void 	printFloat(double value);
	    static void 	printDouble(double value);
	    
	    static bool		isPseudoLiteral(const std::string &literal);
	    static double	getPseudoLiteralValue(const std::string &literal);
	public:
		static void	convert(const std::string &str);

};

#endif