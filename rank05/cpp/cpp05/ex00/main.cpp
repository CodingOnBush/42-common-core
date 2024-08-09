#include "Bureaucrat.hpp"

#define PURPLE "\033[1;35m"
#define RED "\033[1;31m"
#define RESET "\033[0m"

static void	print(const std::string msg, const char *color)
{
	std::cout
		<< color
		<< "----- " << msg << " -----" 
		<< RESET 
	<< std::endl;
}

static void	instantiateTooHigh(void)
{
	try
	{
		Bureaucrat	tooHigh("Wrong", 15555);
	}
	catch (std::exception &e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
}

static void	instantiateTooLow(void)
{
	try
	{
		Bureaucrat	tooLow("Wrong", -10);
	}
	catch (std::exception &e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
}

int	main(void)
{
	print("instantiate too high and too low", PURPLE);
	instantiateTooHigh();
	instantiateTooLow();
	
	print("Test accessors and in/de crementGrade", PURPLE);
	try
	{
		Bureaucrat	b1("Michel", 5);
		Bureaucrat	b2("Julie", 1);

		std::cout << "b1's name: " << b1.getName() << std::endl;
		std::cout << "b2's grade: " << b2.getGrade() << std::endl;
		std::cout << "using overloaded operator :" << b2 << std::endl;
		b1.decrementGrade();
		std::cout << "let's have a too high exception :" << std::endl;
		b2.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
}
