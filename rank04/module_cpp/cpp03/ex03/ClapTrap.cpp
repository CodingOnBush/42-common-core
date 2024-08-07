/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:05:26 by momrane           #+#    #+#             */
/*   Updated: 2024/05/28 14:44:56 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	this->name_ = "";
	this->hitPoints_ = 10;
	this->energyPoints_ = 10;
	this->attackDamage_ = 0;
	std::cout << MAGENTA
		<< "[CLAP] \tdefault constructor called."
	<< RESET << std::endl;
}

ClapTrap::ClapTrap(std::string name) : 
	name_(name),
	hitPoints_(10),
	energyPoints_(10),
	attackDamage_(0)
{
	std::cout << MAGENTA
		<< "[CLAP] \t(" << this->name_ << ") constructor"
	<< RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& obj)
{
	*this = obj;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& obj)
{
	this->hitPoints_ = obj.hitPoints_;
	this->energyPoints_ = obj.energyPoints_;
	this->attackDamage_ = obj.attackDamage_;
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << MAGENTA
		<< "[CLAP] \tdestructor called for (" << this->name_ << ")."
	<< RESET << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->hitPoints_ <= 0 || this->energyPoints_ <= 0)
	{
		std::cout << MAGENTA
			<< "[CLAP] \tattack(" << target << ") -> " 	<< this->name_
			<< " can't attack!"
		<< RESET << std::endl;
		return ;
	}
	this->energyPoints_--;
	std::cout << MAGENTA
		<< "[CLAP] \tattack(" << target << ") -> " 	<< this->name_
		<< " attacks " << target 
		<< ", causing " << this->attackDamage_ << " points of damage!" 
	<< RESET << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << MAGENTA
		<< "[CLAP] \ttakeDamage(" << amount << ") -> " 	<< this->name_
		<< " take " << amount << " points of damage!" 
	<< RESET << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hitPoints_ <= 0 || this->energyPoints_ <= 0)
	{
		std::cout << MAGENTA
			<< "[CLAP] \tbeRepaired(" << amount << ") -> " 	<< this->name_
			<< " can't be repaired!"
		<< RESET << std::endl;
		return ;
	}
	this->hitPoints_ += amount;
	this->energyPoints_--;
	std::cout << MAGENTA
		<< "[CLAP] \tbeRepaired(" << amount << ") -> " 	<< this->name_
		<< " be repaired for " << amount << " points!" 
	<< RESET << std::endl;
}
