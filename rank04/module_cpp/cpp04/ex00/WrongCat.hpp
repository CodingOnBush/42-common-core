/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 17:25:53 by momrane           #+#    #+#             */
/*   Updated: 2024/05/28 17:45:17 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include <iostream>
# include "WrongAnimal.hpp"

# define YELLOW	"\033[33m"
# define RESET	"\033[0m"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat(void);						// default constructor
		WrongCat(const WrongCat& obj);		// copy constructor
		WrongCat &operator=(const WrongCat& obj);	// assignation operator
		~WrongCat(void);					// destructor

		void	makeSound(void) const;
};

#endif