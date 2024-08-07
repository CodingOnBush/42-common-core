/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:58:53 by momrane           #+#    #+#             */
/*   Updated: 2024/05/28 14:32:59 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

# define GREEN	"\e[1;32m"
# define RESET	"\033[0m"

class FragTrap : virtual public ClapTrap
{
	public:
		FragTrap(void);								// default constructor
		FragTrap(const FragTrap& obj);				// copy constructor
		FragTrap & operator=(const FragTrap& obj);	// assignation operator
		~FragTrap(void);							// destructor
		
		FragTrap(std::string name);
		
		void	highFivesGuys(void);
};

#endif