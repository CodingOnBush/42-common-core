/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:18:27 by momrane           #+#    #+#             */
/*   Updated: 2024/05/16 17:18:28 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

void	testInStack(void)
{
	std::cout << "Let's create a random Zombie in the stack named Luffy." << std::endl;
	randomChump("Luffy");
}

void	testInHeap(void)
{
	Zombie	*michel;

	std::cout << "Let's create a new Zombie named Michel in the heap." << std::endl;
	michel = newZombie("Michel");
	if (!michel)
	{
		std::cerr << "Failed to create a new Zombie." << std::endl;
		return ;
	}
	std::cout << "Let's make Michel announce himself." << std::endl;
	michel->announce();
	std::cout << "Let's make Michel die." << std::endl;
	delete michel;
}

int	main(void)
{
	std::cout << "╔═══════════════════════════════════════════╗" << std::endl;
	std::cout << "║ Let's test the Zombie class in the STACK. ║" << std::endl;
	std::cout << "╚═══════════════════════════════════════════╝" << std::endl;
	testInStack();

	std::cout << "╔═══════════════════════════════════════════╗" << std::endl;
	std::cout << "║ Let's test the Zombie class in the HEAP.  ║" << std::endl;
	std::cout << "╚═══════════════════════════════════════════╝" << std::endl;
	testInHeap();
	return (0);
}
