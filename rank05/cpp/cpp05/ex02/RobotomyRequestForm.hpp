#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <ctime>
# include <cstdlib>

class RobotomyRequestForm : public AForm
{
	private:
		std::string	_target;
	public:
		/* coplien's form */
		RobotomyRequestForm();											// default constructor
		RobotomyRequestForm(const RobotomyRequestForm &src);			// copy constructor
		RobotomyRequestForm &operator=(const RobotomyRequestForm &src);	// assignment operator
		~RobotomyRequestForm();											// destructor

		RobotomyRequestForm(const std::string target);

		void	execute(Bureaucrat const & executor) const;
};

#endif
