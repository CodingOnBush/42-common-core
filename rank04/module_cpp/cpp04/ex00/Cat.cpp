/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:05:10 by momrane           #+#    #+#             */
/*   Updated: 2024/06/02 17:39:25 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	this->type = "Cat";
	std::cout << YELLOW << "[CAT] constructor" << RESET << std::endl;
}

Cat::Cat(const Cat& obj)
{
	std::cout << YELLOW << "[CAT] copy constructor" << RESET << std::endl;
	*this = obj;
}

Cat &Cat::operator=(const Cat& obj)
{
	std::cout << YELLOW << "[CAT] assignation operator" << RESET << std::endl;
	this->type = obj.type;
	return (*this);
}

Cat::~Cat(void)
{
	std::cout << YELLOW << "[CAT] destructor" << RESET << std::endl;
}

void Cat::makeSound(void) const
{
	std::cout << YELLOW << "[CAT] : Miaou Miaou" << RESET << std::endl;
}
