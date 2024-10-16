#include "./inc/ScalarConverter.hpp"

static int	err(const std::string &msg)
{
	std::cerr << msg << std::endl;
	return 1;
}

static bool	strIsDisplayable(const std::string &str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!isprint(str[i]))
			return false;
	}
	return true;
}

int	main(int ac, char **av)
{
	std::string	str;

	if (ac !=2)
		return err("Usage: ./convert [string]");
	str = av[1];
	if (str.empty())
		return err("Error: empty string");
	if (!strIsDisplayable(str))
		return err("Error: string is not displayable");
	ScalarConverter::convert(str);
	return 0;
}

/*
./convert 0
char: Non displayable
int: 0
float: 0.0f
double: 0.0
./convert nan
char: impossible
int: impossible
float: nanf
double: nan
./convert 42.0f
char: '*'
int: 42
float: 42.0f
double: 42.0
*/


/*
// std::string char_str = "*";
// ScalarConverter::convert(char_str);

// std::string i_int = "0";
// ScalarConverter::convert(i_int);
// std::string i_min_str = "-2147483648";
// ScalarConverter::convert(i_min_str);
// std::string i_max_str = "2147483647";
// ScalarConverter::convert(i_max_str);

// std::string f_min_str = "1.17549e-38";
// ScalarConverter::convert(f_min_str);
// std::string f_max_str = "3.40282e+38";
// ScalarConverter::convert(f_max_str);
// ScalarConverter::convert("nanf");
// ScalarConverter::convert("-inff");
// ScalarConverter::convert("+inff");

// std::string d_max_str = "1.79769e+308";
// ScalarConverter::convert(d_max_str);
// std::string d_min_str = "2.22507e-308";
// ScalarConverter::convert(d_min_str);
// ScalarConverter::convert("nan");
// ScalarConverter::convert("-inf");
// ScalarConverter::convert("+inf");

// std::string test_str = "1.8e308";
// ScalarConverter::convert(test_str);
*/