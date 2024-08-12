#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
public:
	/* Coplien's form */
	Intern();								// default constructor
	Intern(const Intern &src);				// copy constructor
	Intern &operator=(const Intern &src);	// assignment operator
	~Intern();								// destructor
	
	AForm	*makeForm(const std::string formName, const std::string target);
};

#endif