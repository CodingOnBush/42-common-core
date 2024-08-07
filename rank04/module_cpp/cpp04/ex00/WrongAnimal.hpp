/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 17:25:37 by momrane           #+#    #+#             */
/*   Updated: 2024/05/28 17:43:49 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

# define RED	"\033[31m"
# define RESET	"\033[0m"

class WrongAnimal
{
	protected:
		std::string type;

	public:
		WrongAnimal(void);						// default constructor
		WrongAnimal(const WrongAnimal& obj);	// copy constructor
		WrongAnimal &operator=(const WrongAnimal& obj);	// assignation operator
		~WrongAnimal(void);						// destructor

		void	makeSound(void) const;
};

#endif