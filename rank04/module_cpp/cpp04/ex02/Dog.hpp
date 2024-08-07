/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:08:07 by momrane           #+#    #+#             */
/*   Updated: 2024/06/12 16:07:09 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include "AAnimal.hpp"
#include "Brain.hpp"

#define CYAN "\033[36m"
#define RESET "\033[0m"

class Dog : public AAnimal
{
private:
	Brain *_brain;

public:
	Dog(void);						// default constructor
	Dog(const Dog &obj);			// copy constructor
	Dog &operator=(const Dog &obj); // assignation operator
	~Dog(void);						// destructor

	virtual void makeSound(void) const;
};

#endif