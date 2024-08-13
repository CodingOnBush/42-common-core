# Exercice 00 - CPP06
In this exercise, we have to write a class that will contain only this static method :
```cpp
static void	convert(std::string const &str);
```
This method will take a string as parameter a string representation of a C++ literal in its most common\
form and output its value in the following serie of scalar types : char, int, float and double.\
A literal is a notation for representing like : 42, -42.42f, 42.42, 'a', "42".\
"hello" is not a literal, it is a string.\
Output means that the method will print the value of the literal followed by a newline.\
As this class doesn’t need to store anything at all, this class must not be instanciable by users so the constructor must be private :
```cpp
class ScalarConverter
{
	private:
		ScalarConverter();// Default constructor
		/* and more to respect the coplien form... */
	public:
		static void	convert(std::string const &str);
};
```
Except for char parameters, only the decimal notation will be used.\
If we have this input : "42.42f", the output will be :
```
char: Non displayable
int: 42
float: 42.42f
double: 42.42
```
If we have a char parameter, the output will be :
```
char: 'a'
int: 97
float: 97.0f
double: 97.0
```
Examples of char literals: ’c’, ’a’, ...\
To make things simple, please note that non displayable characters shouldn’t be used as inputs. If a conversion to char is not displayable, prints an informative message (Not displayable).\
We have to handle -inff, +inff and nanf for floats.\
We have to handle -inf, +inf and nan for doubles.\
### Conversion
For example, to convert a string to an int, we can do :
```cpp
int		n = std::stoi("42");
float	f = std::stof("42.42f");
double	d = std::stod("42.42");
```
We can use the std::stod, std::stof and std::stoi functions beacause they are defined in the std namespace and in the section "Allowed functions" there is : "Any function to convert from a string to an int, a float or a double. This will help, but won’t do the whole job."\
### Identify the type
To identify the type of the literal, we can use the following functions :
```cpp
bool	isChar(std::string const &str);
bool	isInt(std::string const &str);
bool	isFloat(std::string const &str);
bool	isDouble(std::string const &str);
```
#### isChar
This function will return true if the string is a char literal.\
A char literal is a string that contains only one character between single quotes.\
For example, 'a', 'b', 'c', ...\
```cpp
bool	isChar(std::string const &str)
{
	if (str.length() == 3 && str[0] == '\'' && str[2] == '\'')
		return (true);
	return (false);
}
```
#### isInt
This function will return true if the string is an int literal.\
An int literal is a string that contains only digits.\
For example, "42", "-42", "0", ...\
```cpp
bool	isInt(std::string const &str)
{
	size_t	i = 0;

	if (str[i] == '-')
		i++;
	while (i < str.length())
	{
		if (!std::isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}
```
#### isFloat
This function will return true if the string is a float literal.\
A float literal is a string that contains digits and a dot.\
For example, "42.42", "-42.42", "0.0", ...\

#### isDouble
