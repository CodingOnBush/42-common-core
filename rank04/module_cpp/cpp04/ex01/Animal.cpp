/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:05:26 by momrane           #+#    #+#             */
/*   Updated: 2024/06/12 15:43:54 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
	: type("default type")
{
	std::cout << MAGENTA << "[ANIMAL] default constructor called" << RESET << std::endl;
}

Animal::Animal(const Animal &obj)
{
	std::cout << MAGENTA << "[ANIMAL] copy constructor called" << RESET << std::endl;
	*this = obj;
}

Animal &Animal::operator=(const Animal &obj)
{
	std::cout << MAGENTA << "[ANIMAL] assignation operator overload called" << RESET << std::endl;
	if (this != &obj)
		this->type = obj.type;
	return (*this);
}

Animal::~Animal(void)
{
	std::cout << MAGENTA << "[ANIMAL] destructor called" << RESET << std::endl;
}

std::string Animal::getType(void) const
{
	return (this->type);
}

void Animal::makeSound(void) const
{
	std::cout << MAGENTA << "[ANIMAL] making a sound" << RESET << std::endl;
}
