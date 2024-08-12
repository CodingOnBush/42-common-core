#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern &src)
{
	if (this != &src)
		*this = src;
}

Intern &Intern::operator=(const Intern &src)
{
	if (this != &src)
		*this = src;
	return (*this);
}

Intern::~Intern()
{
}

AForm *Intern::makeForm(const std::string formName, const std::string target)
{
	std::string	formNames[3] = {
		"shrubbery creation", 
		"robotomy request", 
		"presidential pardon"
	};
	AForm	*forms[3] = {
		new ShrubberyCreationForm(target),
		new RobotomyRequestForm(target),
		new PresidentialPardonForm(target)
	};

	for (int i = 0; i < 3; i++)
	{
		if (formNames[i] == formName)
		{
			std::cout << "Intern creates " << formName << std::endl;
			return (forms[i]);
		}
	}
	std::cout << "Intern cannot create " << formName << std::endl;
	return (NULL);
}
