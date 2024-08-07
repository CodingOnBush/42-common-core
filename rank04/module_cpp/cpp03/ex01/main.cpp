/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:59:24 by momrane           #+#    #+#             */
/*   Updated: 2024/06/02 11:44:48 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	// Test ClapTrap
	{
		ClapTrap	clap("clapisto");
		
		clap.takeDamage(10);
		clap.beRepaired(10);
		clap.attack("enemy");
	}
	
	std::cout << std::endl << std::endl;
	
	// Test ScavTrap
	{
		ScavTrap	scav("scavisto");

		scav.takeDamage(10);
		scav.beRepaired(10);
		scav.attack("enemy");
		scav.guardGate();
	}
	return (0);
}
