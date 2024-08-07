/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:05:26 by momrane           #+#    #+#             */
/*   Updated: 2024/05/28 14:45:14 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void)
{
	this->hitPoints_ = FragTrap::hitPoints_;
	this->energyPoints_ = ScavTrap::energyPoints_;
	this->attackDamage_ = FragTrap::attackDamage_;
	std::cout << CYAN
		<< "[DIAM] \tdefault constructor called."
	<< RESET << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &obj)
{
	*this = obj;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << CYAN
		<< "[DIAM] \tdestructor called for (" << this->name_ << ")."
	<< RESET << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
{
	this->name_ = name;
	ClapTrap::name_ = name + "_clap_name";
	std::cout << CYAN
		<< "[DIAM] \tconstructor called with (" << this->name_ << ")."
	<< RESET << std::endl;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &obj)
{
	this->name_ = obj.name_;
	return (*this);
}

void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void)
{
	std::cout << CYAN
		<< "[DIAM] \twhoAmI() -> My name is " << this->name_
		<< " and my ClapTrap name is " << ClapTrap::name_
	<< RESET << std::endl;
}
