/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 17:25:52 by momrane           #+#    #+#             */
/*   Updated: 2024/05/28 17:45:18 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	this->type = "WrongCat";
	std::cout << YELLOW << "WrongCat constructor" << RESET << std::endl;
}

WrongCat::WrongCat(const WrongCat& obj)
{
	std::cout << YELLOW << "WrongCat copy constructor" << RESET << std::endl;
	*this = obj;
}

WrongCat &WrongCat::operator=(const WrongCat& obj)
{
	std::cout << YELLOW << "WrongCat assignation operator" << RESET << std::endl;
	this->type = obj.type;
	return (*this);
}

WrongCat::~WrongCat(void)
{
	std::cout << YELLOW << "WrongCat destructor" << RESET << std::endl;
}

void WrongCat::makeSound(void) const
{
	std::cout << YELLOW << "WrongCat : Miaou Miaou" << RESET << std::endl;
}
