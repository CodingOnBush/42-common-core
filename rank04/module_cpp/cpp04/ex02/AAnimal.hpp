/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:58:53 by momrane           #+#    #+#             */
/*   Updated: 2024/06/03 08:06:50 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>

# define MAGENTA	"\033[35m"
# define RESET		"\033[0m"

class AAnimal
{
	protected:
		std::string	type;
		
	public:
		AAnimal(void);							// default constructor
		AAnimal(const AAnimal& obj);			// copy constructor
		AAnimal &operator=(const AAnimal& obj);	// assignation operator
		virtual ~AAnimal(void);					// destructor

		std::string		getType(void) const;
		virtual void	makeSound(void) const = 0;
};

#endif