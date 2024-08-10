#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

class Bureaucrat;

/*
In all cases, the base class Form must be an abstract class, and therefore should be renamed AForm
*/
class AForm
{
private:
	/*
	Keep in mind the form’s attributes need to remain private and that they are in the base class.
	*/
	const std::string	_name;
	bool 				_signed;
	const int 			_signGrade;
	const int 			_execGrade;

public:
	/* coplien's form */
	AForm();							// default constructor
	AForm(const AForm &src);			// copy constructor
	AForm &operator=(const AForm &rhs); // assignment operator
	virtual ~AForm();					// destructor

	AForm(const std::string name, const int signGrade, const int execGrade);

	const std::string	getName() const;
	bool 				getSigned() const;
	int		 			getSignGrade() const;
	int		 			getExecGrade() const;

	void 				beSigned(const Bureaucrat &b);
	void				checkRequirements(const Bureaucrat &b) const;
	virtual void 		execute(Bureaucrat const &executor) const = 0;

public:
	class GradeTooHighException : public std::exception
	{
	public:
		const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		const char *what() const throw();
	};

	class NotSignedException : public std::exception
	{
	public:
		const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &out, const AForm &rhs);

#endif
