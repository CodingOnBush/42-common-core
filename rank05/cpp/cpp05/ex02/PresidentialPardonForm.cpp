#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() :
	AForm("PresidentialPardonForm", 25, 5),
	_target("president")
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src)
{
	if (this != &src)
		_target = src._target;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
	if (this != &src)
	{
		AForm::operator=(src);
		_target = src._target;
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) :
	AForm("PresidentialPardonForm", 25, 5),
	_target(target)
{
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	this->checkRequirements(executor);//could throw exception here
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
