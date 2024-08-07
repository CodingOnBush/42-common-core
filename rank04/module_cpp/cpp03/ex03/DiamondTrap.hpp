/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allblue <allblue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:58:53 by momrane           #+#    #+#             */
/*   Updated: 2024/06/12 09:48:26 by allblue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "FragTrap.hpp"
# include "ScavTrap.hpp"
# include "ClapTrap.hpp"
# include <iostream>

# define CYAN	"\e[1;36m"
# define RESET	"\033[0m"

class DiamondTrap : public FragTrap, public ScavTrap
{
	private:
		std::string	name_;

	public:
		DiamondTrap(void);									// default constructor
		DiamondTrap(DiamondTrap const & obj);				// copy constructor
		DiamondTrap & operator=(DiamondTrap const & obj);	// assignation operator
		~DiamondTrap(void);								// destructor
		
		DiamondTrap(std::string name);
		
		void	attack(const std::string& target);
		void	whoAmI(void);
};

#endif