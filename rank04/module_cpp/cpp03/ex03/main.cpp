/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:59:24 by momrane           #+#    #+#             */
/*   Updated: 2024/06/02 12:01:37 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap	diamisto("diamisto");
	
	std::cout << std::endl;
	
	diamisto.whoAmI();
	diamisto.attack("enemy");
	diamisto.takeDamage(5);
	diamisto.beRepaired(5);
	diamisto.highFivesGuys();
	
	std::cout << std::endl;
	
	return (0);
}
