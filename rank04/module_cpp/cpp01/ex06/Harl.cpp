/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:05:34 by momrane           #+#    #+#             */
/*   Updated: 2024/05/16 18:02:11 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug_(void)
{
	std::string msg = "Increase in fossil fuel extraction linked to global temperature rise.";
	printMsg("DEBUG", msg, GREEN);
}

void Harl::info_(void)
{
	std::string msg = "Scientists establish a clear correlation between greenhouse gas emissions and lobal temperature escalation.";
	printMsg("INFO", msg, CYAN);
}

void Harl::warning_(void)
{
	std::string msg = "Climate change effects on vulnerable populations are reaching critical levels.";
	printMsg("WARNING", msg, YELLOW);
}

void Harl::error_(void)
{
	std::string msg = "Immediate global action is imperative to address the effects of climate change.";
	printMsg("ERROR", msg, RED);
}

Harl::Harl(void)
{
}

Harl::~Harl(void)
{
}

void Harl::complain(std::string level)
{
	std::string	types[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int			mode = 0;
	
	for (; mode < 4; mode++)
	{
		if (level == types[mode])
			break;
	}
	switch (mode)
	{
		default:
			printMsg("It's not a valid level", "Please enter a valid level 🌎", BLUE);
			break;
		case 0:
			this->debug_();
		case 1:
			this->info_();
		case 2:
			this->warning_();
		case 3:
			this->error_();
	}
}

void	printMsg(std::string title, std::string msg, std::string color)
{
	std::cout
		<< color + title + RESET
		<< std::endl
		<< "↳ " + msg 
	<< std::endl;
}
