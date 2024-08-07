/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:05:02 by momrane           #+#    #+#             */
/*   Updated: 2024/05/16 17:15:35 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int	main(void)
{
	Zombie*	horde;
	int		horde_size = 3;

	std::cout << "╔═══════════════════════════════════════════╗" << std::endl;
	std::cout << "║ Let's create a horde of Zombie.           ║" << std::endl;
	std::cout << "╚═══════════════════════════════════════════╝" << std::endl;
	horde = zombieHorde(horde_size, "michel");
	if (!horde)
	{
		std::cerr << "Error: failed to create a horde of Zombie ." << std::endl;
		return (1);
	}
	std::cout << "A horde of " << horde_size << " zombies has been created 😱." << std::endl;
	for (int i = 0; i < horde_size; i++)
	{
		std::cout << "[" << i << "] ";
		horde[i].announce();
	}
	delete [] horde;
	return (0);
}
