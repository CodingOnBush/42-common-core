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
	std::string		filename = _target + "_shrubbery";
	std::ofstream	file;

	this->checkRequirements(executor);
	file.open(filename.c_str());
	if (!file.is_open())
		std::cerr << "Error: could not open file" << std::endl;
	else
	{
		file << "                      ___" << std::endl;
		file << "                _,-'""   """"`--." << std::endl;
		file << "             ,-'          __,,-- \\" << std::endl;
		file << "           ,'    __,--""""dF      )" << std::endl;
		file << "          /   .-\"Hb_,--\"\"dF      /" << std::endl;
		file << "        ,'       _Hb ___dF\"-._,-'" << std::endl;
		file << "      ,'      _,-\"\"\"\"   \"\"--..__" << std::endl;
		file << "     (     ,-'                  `." << std::endl;
		file << "      `._,'     _   _             ;" << std::endl;
		file << "       ,'     ,' `-'Hb-.___..._,-'" << std::endl;
		file << "       \\    ,'\"Hb.-'HH`-.dHF\"" << std::endl;
		file << "        `--'   \"Hb  HH  dF\"" << std::endl;
		file << "                \"Hb HH dF" << std::endl;
		file << "                 \"HbHHdF" << std::endl;
		file << "                  |HHHF" << std::endl;
		file << "                  |HHH|" << std::endl;
		file << "                  |HHH|" << std::endl;
		file << "                  |HHH|" << std::endl;
		file << "                  |HHH|" << std::endl;
		file << "                  dHHHb" << std::endl;
		file << "                .dFd|bHb.               o" << std::endl;
		file << "      o       .dHFdH|HbTHb.          o /" << std::endl;
		file << "\\  Y  |  \\__,dHHFdHH|HHhoHHb.__Krogg  Y" << std::endl;
		file << "##########################################" << std::endl;
		file << std::endl;
		file.close();
		if (file.fail())
			std::cerr << "cannot close the file " << _target << "_shrubbery" << std::endl;
		else
			std::cout << "Shrubbery has been created in " << _target << "_shrubbery" << std::endl;
	}
}
