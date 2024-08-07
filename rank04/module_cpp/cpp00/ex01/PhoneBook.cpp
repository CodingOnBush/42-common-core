/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:06:11 by momrane           #+#    #+#             */
/*   Updated: 2024/05/14 14:26:39 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./PhoneBook.hpp" 
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>

static void	printWelcome(void)
{
	std::cout << boldyellow << "╔═══════════════════════════════════════════╗" << reset << std::endl;
	std::cout << boldyellow << "║   Welcome in this awesome Phone Book 🌸   ║" << reset << std::endl;
	std::cout << boldyellow << "╚═══════════════════════════════════════════╝" << reset << std::endl;
	return ;
}

static void	printGoodBye(void)
{
	std::cout << boldyellow << "══════════════ GOODBYE 👋👋👋 ═══════════════" << reset << std::endl;
	return ;
}

static void	printUsage(void)
{
	std::cout << "╔═══════════ Commands available ════════════╗" << std::endl;
	std::cout << "║ ADD    : Add a new contact                ║" << std::endl;
	std::cout << "║ SEARCH : Search a contact                 ║" << std::endl;
	std::cout << "║ EXIT   : Exit the Phone Book              ║" << std::endl;
	std::cout << "╚═══════════════════════════════════════════╝" << std::endl;
	return ;
}

PhoneBook::PhoneBook(void)
{
	this->_added = 0;
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

void	PhoneBook::_printPhoneBook(void)
{
	std::cout << boldyellow << "╔══════════╦═ YOUR PHONE BOOK ! ═╦══════════╗" << reset << std::endl;
	std::cout << boldyellow << "║   index  ║firstname ║ lastname ║ nickname ║" << reset << std::endl;
	std::cout << boldyellow << "╠══════════╬══════════╬══════════╬══════════╣" << reset << std::endl;
	for (int i = 0; i < 8; i++)
	{
		if (this->_added == 0)
			break ;
		if (this->_added < 8 && i >= (this->_added % 8))
			break ;
		std::cout << boldyellow << "║" << reset;
		std::cout << std::setw(10) << std::right << (i + 1) << boldyellow << "║" << reset;
		this->_contacts[i].printLineContact();
		std::cout << std::endl;
	}
	if (this->_added == 0)
		std::cout << "║         The Phone Book is empty.          ║" << std::endl;
	std::cout << boldyellow << "╚══════════╩══════════╩══════════╩══════════╝" << reset << std::endl;
	return ;
}

void	PhoneBook::_addContact(void)
{
	int	index;

	std::cout << boldblue << "══════════ Adding a new contact... ══════════" << reset << std::endl;
	index = this->_added % 8;
	this->_added++;
	this->_contacts[index].fillContact();
	std::cout << boldblue << "═════════════════════════════════════════════" << reset << std::endl;
	std::cout << boldgreen << "A new contact has been added successfully 🎉" << reset << std::endl;
	return ;
}

static int	getIndex(std::string str)
{
	if (str.length() != 1 || !std::isdigit(str[0]))
		return (-1);
	return (std::atoi(str.c_str()));
}

void	PhoneBook::_searchContact(void)
{
	std::string	input = "";
	int			index;

	_printPhoneBook();
	if (this->_added == 0)
	{
		std::cout << boldred << "There is no contact to search for 😖" << reset << std::endl;
		return ;
	}
	std::cout << boldblue << "═════════ Searching a new contact... ════════" << reset << std::endl;
	while (1)
	{
		std::cout << "Enter the index you want to search :";
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cout << std::endl;
			return ;
		}
		index = getIndex(input);
		if (index >= 1 && index <= 8)
			break;
		std::cout << boldred << "Please entre a single number between 1 and 8" << reset << std::endl;
	}
	if (index <= (this->_added % 8) || this->_added >= 8)
	{
		std::cout << green << "═══════════════ [CONTACT nº" << index << "] ═══════════════" << reset << std::endl;
		this->_contacts[index - 1].printFullInfos();
	}
	else
		std::cout << red << "This contact doesn't exist 😖" << reset << std::endl;
	std::cout << boldblue << "═════════════════════════════════════════════" << reset << std::endl;
}

void	PhoneBook::launchApp(void)
{
	std::string	input;

	printWelcome();
	printUsage();
	while (!std::cin.eof())
	{
		std::cout << boldyellow << "Please, enter a command > " << reset;
		std::getline(std::cin, input);
		if (std::cin.eof() || !input.compare("EXIT"))
		{
			std::cout << std::endl;
			break;
		}
		else if (!input.compare("ADD"))
			this->_addContact();
		else if (!input.compare("SEARCH"))
			this->_searchContact();
		else if (!input.empty())
		{
			std::cout << red << "Please enter a valid command 😊" << reset << std::endl;
			printUsage();
		}
	}
	printGoodBye();
}
