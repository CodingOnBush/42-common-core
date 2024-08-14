#include "Form.hpp"
#include "Bureaucrat.hpp"

const char	*Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high !");
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low !");
}

const char	*Form::FormAlreadySignedException::what() const throw()
{
	return ("Form is already signed !");
}

Form::Form(void) : 
	_name("default name"), 
	_signed(false), 
	_signGrade(150), 
	_execGrade(150)
{
}

Form::Form(const Form &src) : 
	_name(src._name), 
	_signed(src._signed), 
	_signGrade(src._signGrade), 
	_execGrade(src._execGrade)
{
	if (src._signGrade > 150 || src._execGrade > 150)
		throw Form::GradeTooLowException();
	else if (src._signGrade < 1 || src._execGrade < 1)
		throw Form::GradeTooHighException();
}

Form &Form::operator=(const Form &rhs)
{
	if (this != &rhs)
		_signed = rhs._signed;
	return (*this);
}

Form::~Form(void)
{
}

Form::Form(const std::string name, const int signGrade, const int execGrade) : 
	_name(name), 
	_signGrade(signGrade), 
	_execGrade(execGrade)
{
	_signed = false;
	if (signGrade > 150 || execGrade > 150)
		throw Form::GradeTooLowException();
	else if (signGrade < 1 || execGrade < 1)
		throw Form::GradeTooHighException();
}

const std::string Form::getName() const
{
	return _name;
}

bool Form::getSigned() const
{
	return _signed;
}

int Form::getSignGrade() const
{
	return _signGrade;
}

int Form::getExecGrade() const
{
	return _execGrade;
}

void Form::beSigned(const Bureaucrat &b)
{
	if (_signed)
		throw Form::FormAlreadySignedException();
	if (b.getGrade() <= _signGrade)
		_signed = true;
	else
		throw Form::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &out, const Form &rhs)
{
	out << "["
		<< "name: " << rhs.getName()
		<< ", signed: " << rhs.getSigned()
		<< ", sign grade: " << rhs.getSignGrade()
		<< ", exec grade: " << rhs.getExecGrade()
	<< "]";
	return (out);
}
