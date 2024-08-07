/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:05:26 by momrane           #+#    #+#             */
/*   Updated: 2024/06/02 11:55:20 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
	this->name_ = "";
	this->hitPoints_ = 100;
	this->energyPoints_ = 100;
	this->attackDamage_ = 30;
	std::cout
		<< GREEN
		<< "[FRAG] \tdefault constructor called."
		<< RESET
	<< std::endl;
}

FragTrap::FragTrap(std::string name)
{
	this->name_ = name;
	this->hitPoints_ = 100;
	this->energyPoints_ = 100;
	this->attackDamage_ = 30;
	std::cout
		<< GREEN
		<< "[FRAG] \tconstructor called with (" << this->name_ << ")."
		<< RESET
	<< std::endl;
}

FragTrap::FragTrap(FragTrap const & obj)
{
	this->name_ = obj.name_;
	this->hitPoints_ = obj.hitPoints_;
	this->energyPoints_ = obj.energyPoints_;
	this->attackDamage_ = obj.attackDamage_;
}

FragTrap::~FragTrap(void)
{
	std::cout
		<< GREEN
		<< "[FRAG] \tdestructor called for (" << this->name_ << ")."
		<< RESET
	<< std::endl;
}

FragTrap & FragTrap::operator=(FragTrap const & obj)
{
	this->name_ = obj.name_;
	this->hitPoints_ = obj.hitPoints_;
	this->energyPoints_ = obj.energyPoints_;
	this->attackDamage_ = obj.attackDamage_;
	return (*this);
}

void	FragTrap::highFivesGuys(void)
{
	std::cout
		<< GREEN
		<< "[FRAG] \tHigh fives requested from (" << this->name_ << ")."
		<< RESET
	<< std::endl;
}
