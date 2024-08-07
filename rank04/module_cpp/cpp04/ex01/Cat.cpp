/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:05:10 by momrane           #+#    #+#             */
/*   Updated: 2024/06/12 15:58:36 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	std::cout << YELLOW << "[CAT] constructor" << RESET << std::endl;
	this->type = "Cat";
	this->_brain = new Brain();
}

Cat::Cat(const Cat &obj)
{
	std::cout << YELLOW << "[CAT] copy constructor" << RESET << std::endl;
	if (this != &obj)
	{
		this->type = obj.type;
		this->_brain = new Brain(*obj._brain);
	}
}

Cat &Cat::operator=(const Cat &obj)
{
	std::cout << YELLOW << "[CAT] assignation operator" << RESET << std::endl;
	if (this != &obj)
	{
		this->type = obj.type;
		delete this->_brain;
		this->_brain = new Brain(*obj._brain);
	}
	return (*this);
}

Cat::~Cat(void)
{
	std::cout << YELLOW << "[CAT] destructor" << RESET << std::endl;
	delete this->_brain;
}

void Cat::makeSound(void) const
{
	std::cout << YELLOW << "[CAT] : Miaou Miaou" << RESET << std::endl;
}
