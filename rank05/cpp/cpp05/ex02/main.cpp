#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void)
{
	// AForm f("f1", 1, 1);//impossible to create an abstract form
	AForm					*form = new PresidentialPardonForm("ptr");
	Bureaucrat				executor("executor", 1);
	PresidentialPardonForm	ppf("ppf");// only one parameter
	RobotomyRequestForm		rrf("rrf");// only one parameter
	ShrubberyCreationForm	scf("scf");// only one parameter

	std::cout << ppf << std::endl;
	std::cout << rrf << std::endl;
	std::cout << scf << std::endl;
	std::cout << *form << std::endl;
	std::cout << executor << std::endl;
	try
	{
		ppf.beSigned(executor);
		rrf.beSigned(executor);
		scf.beSigned(executor);
		form->beSigned(executor);

		std::cout << "------------------" << std::endl;
		ppf.execute(executor);
		rrf.execute(executor);
		rrf.execute(executor);
		scf.execute(executor);
		form->execute(executor);
		std::cout << "------------------" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "------------------" << std::endl;
	executor.executeForm(*form);
	std::cout << "------------------" << std::endl;

	delete form;
	return (0);
}
