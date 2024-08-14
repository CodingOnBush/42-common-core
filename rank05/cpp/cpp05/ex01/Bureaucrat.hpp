#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include "Form.hpp"

#include <iostream>
#include <string>
#include <exception>

class Form;

class Bureaucrat
{
	private:
		const std::string	_name;
		int 				_grade;

	public:
		/* coplien's form */
		Bureaucrat(void);								// default constructor
		Bureaucrat(const Bureaucrat &src);				// copy constructor
		Bureaucrat &operator=(const Bureaucrat &rhs);	// assignment operator
		~Bureaucrat(void);								// destructor

		Bureaucrat(std::string name, int grade);
		
		/* accessors */
		const std::string	getName() const;
		int					getGrade() const;
		
		void				incrementGrade();
		void				decrementGrade();
		void				signForm(Form &f);

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
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &rhs);

#endif
