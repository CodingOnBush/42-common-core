/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 13:55:50 by momrane           #+#    #+#             */
/*   Updated: 2024/05/16 17:49:36 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.h"

int	main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr << RED << "Usage: ./a.out <filename> <str1> <str2>" << RESET << std::endl;
		return (1);
	}
	std::string	filename(av[1]);
	std::string	s1(av[2]);
	std::string	s2(av[3]);
	std::string	outfile = filename + ".replace";
	return (sed(filename, s1, s2, outfile));
}
