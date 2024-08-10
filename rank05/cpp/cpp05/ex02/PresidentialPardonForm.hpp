#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string	_target;

	public:
		/* coplien's form */
		PresidentialPardonForm();												// default constructor
		PresidentialPardonForm(const PresidentialPardonForm &src);				// copy constructor
		PresidentialPardonForm &operator=(const PresidentialPardonForm &src);	// assignment operator
		~PresidentialPardonForm();												// destructor

		PresidentialPardonForm(const std::string target);

		void	execute(Bureaucrat const &executor) const;
};

#endif
