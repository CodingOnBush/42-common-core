#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() :
	AForm("RobotomyRequestForm", 72, 45),
	_target("robotomy")
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)
{
	if (this != &src)
		_target = src._target;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	if (this != &src)
	{
		AForm::operator=(src);// copy the parent class members
		_target = src._target;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) :
	AForm("RobotomyRequestForm", 72, 45),
	_target(target)
{
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	static int count = 0;
	this->checkRequirements(executor);// Could throw an exception
	std::cout << "* drilling noises * ";
	if (count % 2)
		std::cout << _target << " has been robotomized successfully" << std::endl;
	else
		std::cout << _target << " robotomization failed" << std::endl;
	count++;
}
