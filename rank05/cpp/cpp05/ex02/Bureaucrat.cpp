#include "Bureaucrat.hpp"
#include "AForm.hpp"

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high !");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low !");
}

Bureaucrat::Bureaucrat(void) : _name("Default name"), _grade(150) {}

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name)
{
	if (grade > _maxGrade)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < _minGrade)
		throw Bureaucrat::GradeTooHighException();
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
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}

void	Bureaucrat::decrementGrade(void)
{
	if (_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
}

void	Bureaucrat::signAForm(AForm &f)
{
	try
	{
		f.beSigned(*this);
		std::cout << _name << " signed " << f.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout
			<< _name << " couldn’t sign " << f.getName()
			<< " because " << e.what() << "."
		<< std::endl;
	}
}

void	Bureaucrat::executeForm(const AForm &form)
{
	try
	{
		form.execute(*this);
		std::cout << _name << " executes " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout
			<< _name << " couldn’t execute " << form.getName()
			<< " because " << e.what() << "."
		<< std::endl;
	}
}

std::ostream	&operator<<(std::ostream &out, Bureaucrat const &rhs)
{
	out << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
	return (out);
}
