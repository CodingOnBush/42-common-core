/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:59:24 by momrane           #+#    #+#             */
/*   Updated: 2024/06/02 11:07:32 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap	luffy("Luffy");
	ClapTrap	arlong("Arlong");
	
	for (size_t i = 1; i < 3; i++)
	{
		luffy.attack("Arlong");
		arlong.takeDamage(0);
		if (i % 2 == 0)
			arlong.beRepaired(1);
	}
	return (0);
}
