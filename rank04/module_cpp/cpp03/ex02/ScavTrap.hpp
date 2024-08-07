/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:44:19 by momrane           #+#    #+#             */
/*   Updated: 2024/06/02 11:46:33 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>

# define YELLOW	"\e[1;33m"
# define RESET	"\033[0m"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap(void);								// default constructor
		ScavTrap(const ScavTrap& obj);				// copy constructor
		ScavTrap & operator=(const ScavTrap& obj);	// assignation operator
		~ScavTrap(void);							// destructor

		ScavTrap(std::string name);
		
		void	attack(const std::string& target);
		//		takeDamage inherited
		//		beRepaired inherited
		void	guardGate(void);
};



#endif