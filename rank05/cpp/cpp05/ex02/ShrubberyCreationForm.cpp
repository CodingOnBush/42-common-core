#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() :
	AForm("ShrubberyCreationForm", 145, 137),
	_target("shrubbery")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
{
	if (this != &src)
		_target = src._target;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	if (this != &src)
	{
		AForm::operator=(src);
		_target = src._target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) :
	AForm("ShrubberyCreationForm", 145, 137),
	_target(target)
{
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	this->checkRequirements(executor);
	std::ofstream	file(_target + "_shrubbery");

	if (!file.is_open())
		std::cerr << "Error: could not open file" << std::endl;
	else
	{
		file << "      /\\      " << std::endl;
		file << "     /\\*\\     " << std::endl;
		file << "    /\\O\\*\\    " << std::endl;
		file << "   /*/\\/\\/\\   " << std::endl;
		file << "  /\\O\\/\\*\\/\\  " << std::endl;
		file << " /\\*\\/\\*\\/\\/\\ " << std::endl;
		file << "/\\O\\/\\/*/\\/O/\\" << std::endl;
		file << "      ||      " << std::endl;
		file << "      ||      " << std::endl;
		file << "      ||      " << std::endl;
		file << std::endl;
		file.close();
		if (file.fail())
			std::cerr << "cannot close the file " << _target << "_shrubbery" << std::endl;
		else
			std::cout << "Shrubbery has been created in " << _target << "_shrubbery" << std::endl;
	}
}
