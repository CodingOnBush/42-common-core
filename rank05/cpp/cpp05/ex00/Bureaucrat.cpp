#include "Bureaucrat.hpp"

const char	*Bureaucrat::TooHighException::what() const throw()
{
	return ("Grade is too high !");
}

const char	*Bureaucrat::TooLowException::what() const throw()
{
	return ("Grade is too low !");
}

Bureaucrat::Bureaucrat(void) : _name("Default name"), _grade(150) {}

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name)
{
	if (grade > _maxGrade)
		throw Bureaucrat::TooLowException();
	else if (grade < _minGrade)
		throw Bureaucrat::TooHighException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) : _name(src._name), _grade(src._grade) {}

Bureaucrat::~Bureaucrat(void) {}

Bureaucrat	&Bureaucrat::operator=(Bureaucrat const &rhs)
{
	if (this != &rhs)
		_grade = rhs._grade;
	return (*this);
}

const std::string	Bureaucrat::getName(void) const
{
	return (_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (_grade);
}

void	Bureaucrat::incrementGrade(void)
{
	if (_grade - 1 < 1)
		throw Bureaucrat::TooHighException();
	_grade--;
}

void	Bureaucrat::decrementGrade(void)
{
	if (_grade + 1 > 150)
		throw Bureaucrat::TooLowException();
	_grade++;
}

std::ostream	&operator<<(std::ostream &out, Bureaucrat const &rhs)
{
	out << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
	return (out);
}