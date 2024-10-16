#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include "AForm.hpp"

#include <iostream>
#include <string>
#include <exception>

class AForm;

class Bureaucrat
{
	private:
		static const int	_minGrade = 1;
		static const int	_maxGrade = 150;
		const std::string	_name;
		int 				_grade;

	public:
		/* coplien's Aform */
		Bureaucrat(void);								// default constructor
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &src);				// copy constructor
		Bureaucrat &operator=(const Bureaucrat &rhs);	// assignment operator
		~Bureaucrat(void);								// destructor

		/* accessors */
		const std::string	getName() const;
		int					getGrade() const;

		void				incrementGrade();
		void				decrementGrade();
		void				signAForm(AForm &f);
		void				executeForm(AForm const & form);

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
