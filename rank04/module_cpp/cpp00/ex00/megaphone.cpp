/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:06:30 by momrane           #+#    #+#             */
/*   Updated: 2024/05/14 14:06:31 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

static void	printToUpperCase(char *str)
{
	char	up;
	int		i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		up = toupper(str[i]);
		std::cout << up;
		i++;
	}
}

static void	megaphone(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
		printToUpperCase(av[i++]);
}

int	main(int ac, char **av)
{
	if (ac <= 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
		megaphone(ac, av);
	std::cout << std::endl;
	return (0);
}
