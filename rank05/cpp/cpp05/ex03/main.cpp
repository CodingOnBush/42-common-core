#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	srand(time(NULL));
	try
	{
		Bureaucrat	b("Bender", 1);
		Intern		someRandomIntern;
		AForm		*rrf;

		// "shrubbery creation" or "robotomy request" or "presidential pardon"
		rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
		rrf->beSigned(b);
		rrf->execute(b);
		delete rrf;
	}
	catch(const std::exception& e)
	{
		std::cerr << "An error occurred: " << e.what() << std::endl;
	}
	return (0);
}
