/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:05:26 by momrane           #+#    #+#             */
/*   Updated: 2024/06/12 16:01:08 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void)
	: type("default type")
{
	std::cout << MAGENTA << "[AANIMAL] default constructor called" << RESET << std::endl;
}

AAnimal::AAnimal(const AAnimal& obj)
{
	std::cout << MAGENTA << "[AANIMAL] copy constructor called" << RESET << std::endl;
	*this = obj;
}

AAnimal &AAnimal::operator=(const AAnimal& obj)
{
	std::cout << MAGENTA << "[AANIMAL] assignation operator overload called" << RESET << std::endl;
	if (this != &obj)
		this->type = obj.type;
	return (*this);
}

AAnimal::~AAnimal(void)
{
	std::cout << MAGENTA << "[AANIMAL] destructor called" << RESET << std::endl;
}

std::string AAnimal::getType(void) const
{
	return (this->type);
}

void AAnimal::makeSound(void) const
{
	std::cout << MAGENTA << "[AANIMAL] making a sound" << RESET << std::endl;
}
