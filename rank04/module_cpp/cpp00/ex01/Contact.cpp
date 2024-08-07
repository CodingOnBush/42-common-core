/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allblue <allblue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:06:18 by momrane           #+#    #+#             */
/*   Updated: 2024/06/12 09:48:26 by allblue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Contact.hpp" 
#include <iostream>
#include <iomanip>
#include <string>

Contact::Contact(void)
{
	this->_firstName = "";
	this->_lastName = "";
	this->_nickname = "";
	this->_phoneNumber = "";
	this->_darkestSecret = "";
	return;
}

Contact::~Contact(void)
{
}

static std::string	getInputStr_(std::string msg)
{
	std::string	input = "";

	while (!std::cin.eof())
	{
		std::cout << msg;
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cout << std::endl;
			break;
		}
		if (!input.empty())
			break;
	}
	return (input);
}

static int	isValidPhoneNumber(std::string input)
{
	if (input.empty())
		return (0);
	if (input[0] != '+' && !std::isdigit(input[0]))
		return (0);
	for (int i = 1; input[i] != '\0'; i++)
	{
		if (!std::isdigit(input[i]))
			return (0);
	}
	return (1);
}

static std::string	getInputNumber_(std::string msg)
{
	std::string	input = "";

	while (!std::cin.eof())
	{
		input = "";
		std::cout << msg;
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cout << std::endl;
			break;
		}
		if (input.empty())
			continue;
		if (isValidPhoneNumber(input))
			break;
		std::cout << red << "Please enter a valid phone number" << reset << std::endl;
	}
	return (input);
}

static void	printInsideColumn(std::string str)
{
	if (str.length() > 10)
		std::cout << std::right << str.substr(0, 9) << boldyellow << ".║" << reset;
	else
		std::cout << std::setw(10) << std::right << str << boldyellow << "║" << reset;
}

void	Contact::fillContact(void)
{
	this->_firstName = getInputStr_("Enter your first name     : ");
	this->_lastName = getInputStr_("Enter your last name      : ");
	this->_nickname = getInputStr_("Enter your nickname       : ");
	this->_phoneNumber = getInputNumber_("Enter your phone number   : ");
	this->_darkestSecret = getInputStr_("Enter your darkest secret : ");
	return ;
}

void	Contact::printLineContact(void) const
{
	printInsideColumn(this->_firstName);
	printInsideColumn(this->_lastName);
	printInsideColumn(this->_nickname);
	return ;
}

void	Contact::printFullInfos(void) const
{
	std::cout << green << "First name     : " << this->_firstName << reset << std::endl;
	std::cout << green << "Last name      : " << this->_lastName << reset << std::endl;
	std::cout << green << "Nickname       : " << this->_nickname << reset << std::endl;
	std::cout << green << "Phone number   : " << this->_phoneNumber << reset << std::endl;
	std::cout << green << "Darkest secret : " << this->_darkestSecret << reset << std::endl;
	return ;
}
