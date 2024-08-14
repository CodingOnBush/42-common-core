#include "AForm.hpp"
#include "Bureaucrat.hpp"

const char	*AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high !");
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low !");
}

const char *AForm::NotSignedException::what() const throw()
{
	return ("Form is not signed");
}

const char	*AForm::FormAlreadySignedException::what() const throw()
{
	return ("Form is already signed !");
}

AForm::AForm() : _name("default"), _signed(false), _signGrade(150), _execGrade(150)
{
}

AForm::AForm(const AForm &src) : _name(src._name), _signed(src._signed), _signGrade(src._signGrade), _execGrade(src._execGrade)
{
	if (src._signGrade > 150 || src._execGrade > 150)
		throw AForm::GradeTooLowException();
	else if (src._signGrade < 1 || src._execGrade < 1)
		throw AForm::GradeTooHighException();
}

AForm &AForm::operator=(const AForm &rhs)
{
	if (this != &rhs)
		_signed = rhs._signed;
	return (*this);
}

AForm::~AForm()
{
}

AForm::AForm(const std::string name, const int signGrade, const int execGrade) : _name(name), _signGrade(signGrade), _execGrade(execGrade)
{
	_signed = false;
	if (signGrade > 150 || execGrade > 150)
		throw AForm::GradeTooLowException();
	else if (signGrade < 1 || execGrade < 1)
		throw AForm::GradeTooHighException();
}

const std::string AForm::getName() const
{
	return _name;
}

bool AForm::getSigned() const
{
	return _signed;
}

int AForm::getSignGrade() const
{
	return _signGrade;
}

int AForm::getExecGrade() const
{
	return _execGrade;
}

void AForm::beSigned(const Bureaucrat &b)
{
	if (_signed)
		throw AForm::FormAlreadySignedException();
	if (b.getGrade() <= _signGrade)
		_signed = true;
	else
		throw AForm::GradeTooLowException();
}

/*
Whether you want to check the requirements in every concrete class or
in the base class (then call another function to execute the form)
is up to you. However, one way is prettier than the other one.
*/
void AForm::checkRequirements(const Bureaucrat &b) const
{
	/*
	You have to check that the form is signed and that the grade of the bureaucrat
	attempting to execute the form is high enough. Otherwise, throw an appropriate exception.
	*/
	if (b.getGrade() > _execGrade)
		throw AForm::GradeTooLowException();
	if (!_signed)
		throw AForm::NotSignedException();
}

std::ostream &operator<<(std::ostream &out, const AForm &rhs)
{
	out << "["
		<< "name: " << rhs.getName()
		<< ", signed: " << rhs.getSigned()
		<< ", sign grade: " << rhs.getSignGrade()
		<< ", exec grade: " << rhs.getExecGrade()
	<< "]";
	return (out);
}
