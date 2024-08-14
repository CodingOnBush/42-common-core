#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>

class ScalarConverter
{
	private:
		ScalarConverter();										// Default constructor
		ScalarConverter(const ScalarConverter &src);			// Copy constructor
		ScalarConverter &operator=(const ScalarConverter &src);	// Assignment operator
		~ScalarConverter();										// Destructor
	public:
		static void	convert(const std::string &str);
};

#endifw