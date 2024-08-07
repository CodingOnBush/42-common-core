/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:01:56 by momrane           #+#    #+#             */
/*   Updated: 2024/06/12 15:58:36 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

#define YELLOW "\033[33m"
#define RESET "\033[0m"

class Cat : public Animal
{
private:
	Brain *_brain;

public:
	Cat(void);						// default constructor
	Cat(const Cat &obj);			// copy constructor
	Cat &operator=(const Cat &obj); // assignation operator
	~Cat(void);						// destructor

	void makeSound(void) const;
};

#endif