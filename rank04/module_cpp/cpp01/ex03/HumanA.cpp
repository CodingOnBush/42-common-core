/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:43:18 by momrane           #+#    #+#             */
/*   Updated: 2024/05/16 17:34:33 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) :
	name_(name),
	weapon_(weapon)
{
}

HumanA::~HumanA(void)
{
}

void HumanA::attack(void)
{
	std::cout
		<< this->name_ 
		<< " attacks with their " 
		<< this->weapon_.getType()
	<< std::endl;
}
