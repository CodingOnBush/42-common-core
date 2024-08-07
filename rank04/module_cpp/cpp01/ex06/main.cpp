/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 13:55:50 by momrane           #+#    #+#             */
/*   Updated: 2024/05/16 16:07:47 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int ac, char **av)
{
	Harl	harl;

	if (ac != 2)
	{
		printMsg("ERROR", "Usage : ./harl [DEBUG, INFO, WARNING, ERROR]", RED);
		return (1);
	}
	harl.complain(av[1]);
	return (0);
}
