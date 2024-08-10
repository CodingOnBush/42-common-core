#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <iostream>

class ShrubberyCreationForm : public AForm
{
	private:
		std::string	_target;

	public:
		/* coplien's form */
		ShrubberyCreationForm();											// default constructor
		ShrubberyCreationForm(const ShrubberyCreationForm &src);			// copy constructor
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);	// assignment operator
		~ShrubberyCreationForm();											// destructor

		ShrubberyCreationForm(const std::string target);

		void	execute(Bureaucrat const & executor) const;
};

#endif
