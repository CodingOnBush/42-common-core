/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:08:41 by momrane           #+#    #+#             */
/*   Updated: 2024/06/02 17:39:39 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	this->type = "Dog";
	std::cout << CYAN << "[DOG] constructor" << RESET << std::endl;
}

Dog::Dog(const Dog& obj)
{
	std::cout << CYAN << "[DOG] copy constructor" << RESET << std::endl;
	*this = obj;
}

Dog &Dog::operator=(const Dog& obj)
{
	std::cout << CYAN << "[DOG] assignation operator" << RESET << std::endl;
	this->type = obj.type;
	return (*this);
}

Dog::~Dog(void)
{
	std::cout << CYAN << "[DOG] destructor" << RESET << std::endl;
}

void Dog::makeSound(void) const
{
	std::cout << CYAN << "[DOG] : Woof Woof" << RESET << std::endl;
}
