#include "Form.hpp"
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
		Form	tooHigh("Wrong", 99999, 99999);
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
		Form	tooLow("Wrong", -99999, -99999);
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
	
	print("Test form's class", PURPLE);
	try
	{
		Bureaucrat	b1("Julie", 1);
		Bureaucrat	b2("Michel", 150);
		Form		f1("Form1", 42, 42);
		Form		f2("Form2", 150, 150);

		std::cout << "test overloaded operator for f1 :" << f1 << std::endl;
		std::cout << "Let's sign f1 with b1 :" << std::endl;
		b1.signForm(f1);
		std::cout << "Let's sign f2 with b2 :" << std::endl;
		b2.signForm(f2);
		std::cout << "Let's try to sign f1 with b2 :" << std::endl;
		b2.signForm(f1);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
}
