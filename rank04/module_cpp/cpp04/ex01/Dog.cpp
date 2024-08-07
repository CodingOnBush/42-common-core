/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:08:41 by momrane           #+#    #+#             */
/*   Updated: 2024/06/12 15:58:36 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	std::cout << CYAN << "[DOG] constructor" << RESET << std::endl;
	this->type = "Dog";
	this->_brain = new Brain();
}

Dog::Dog(const Dog &obj)
{
	std::cout << CYAN << "[DOG] copy constructor" << RESET << std::endl;
	if (this != &obj)
	{
		this->type = obj.type;
		this->_brain = new Brain(*obj._brain);
	}
}

Dog &Dog::operator=(const Dog &obj)
{
	std::cout << CYAN << "[DOG] assignation operator" << RESET << std::endl;
	if (this != &obj)
	{
		this->type = obj.type;
		delete this->_brain;
		this->_brain = new Brain(*obj._brain);
	}
	return (*this);
}

Dog::~Dog(void)
{
	std::cout << CYAN << "[DOG] destructor" << RESET << std::endl;
	delete this->_brain;
}

void Dog::makeSound(void) const
{
	std::cout << CYAN << "[DOG] : Woof Woof" << RESET << std::endl;
}
