#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

class Bureaucrat;

class Form
{
private:
	const std::string	_name;
	bool				_signed;
	const int			_signGrade;
	const int			_execGrade;
public:
	/* coplien's form */
	Form(void);							// default constructor
	Form(const Form &src);				// copy constructor
	Form &operator=(const Form &rhs);	// assignment operator
	~Form(void);						// destructor
	
	Form(const std::string name, const int signGrade, const int execGrade);

	/* accessors */
	const std::string	getName() const;
	bool				getSigned() const;
	int					getSignGrade() const;
	int					getExecGrade() const;

	void				beSigned(const Bureaucrat &b);
public:
	class GradeTooHighException : public std::exception
	{
		public:
			const char*	what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
			const char*	what() const throw();
	};

	class FormAlreadySignedException : public std::exception
	{
		public:
			const char*	what() const throw();
	};
};

std::ostream &operator<<(std::ostream &out, const Form &rhs);

#endif