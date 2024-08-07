/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 17:25:35 by momrane           #+#    #+#             */
/*   Updated: 2024/05/28 17:44:04 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
	this->type = "WrongAnimal";
	std::cout << RED << "WrongAnimal constructor" << RESET << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& obj)
{
	std::cout << RED << "WrongAnimal copy constructor" << RESET << std::endl;
	*this = obj;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal& obj)
{
	std::cout << RED << "WrongAnimal assignation operator" << RESET << std::endl;
	this->type = obj.type;
	return (*this);
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << RED << "WrongAnimal destructor" << RESET << std::endl;
}

void WrongAnimal::makeSound(void) const
{
	std::cout << RED << "WrongAnimal making a sound" << RESET << std::endl;
}
