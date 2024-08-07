/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:58:53 by momrane           #+#    #+#             */
/*   Updated: 2024/06/12 15:54:39 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

#define MAGENTA "\033[35m"
#define RESET "\033[0m"

class Animal
{
protected:
	std::string type;

public:
	Animal(void);						  // default constructor
	Animal(const Animal &obj);			  // copy constructor
	Animal &operator=(const Animal &obj); // assignation operator
	virtual ~Animal(void);				  // destructor

	std::string getType(void) const;
	virtual void makeSound(void) const;
};

#endif