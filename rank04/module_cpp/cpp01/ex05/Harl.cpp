/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:05:34 by momrane           #+#    #+#             */
/*   Updated: 2024/05/16 18:10:07 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug_(void)
{
	std::string msg = "Increase in fossil fuel extraction linked to global temperature rise.";
	std::cout << GREEN << "DEBUG\t: " << RESET << msg << std::endl;
}

void Harl::info_(void)
{
	std::string msg = "Scientists establish a clear correlation between greenhouse gas emissions and lobal temperature escalation.";
	std::cout << CYAN << "INFO\t: " << RESET << msg << std::endl;
}

void Harl::warning_(void)
{
	std::string msg = "Climate change effects on vulnerable populations are reaching critical levels.";
	std::cout << YELLOW << "WARNING\t: " << RESET << msg << std::endl;
}

void Harl::error_(void)
{
	std::string msg = "Immediate global action is imperative to address the effects of climate change.";
	std::cout << RED << "ERROR\t: " << RESET << msg << std::endl;
}

Harl::Harl(void)
{
}

Harl::~Harl(void)
{
}

void Harl::complain(std::string level)
{
	std::string types[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*funcs[4])(void) = {&Harl::debug_, &Harl::info_,
		&Harl::warning_, &Harl::error_};
	if (level.empty())
		return ;
	for (size_t i = 0; i < 4; i++)
	{
		if (level.compare(types[i]) == 0)
		{
			(this->*funcs[i])();
			return ;
		}
	}
}
