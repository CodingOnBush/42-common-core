#include "Form.hpp"
#include "Bureaucrat.hpp"

int	main(void)
{	
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
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return (0);
}
