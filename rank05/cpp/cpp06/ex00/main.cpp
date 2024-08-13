#include "./inc/ScalarConverter.hpp"

int	main(int ac, char **av)
{
	if (ac !=2 )
	{
		std::cerr << "Usage: ./convert [value]" << std::endl;
		return 1;
	}
	ScalarConverter::convert(av[1]);
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