/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:51:12 by momrane           #+#    #+#             */
/*   Updated: 2024/05/27 16:58:31 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : rawValue_(0)
{
	std::cout
		<< "Default constructor called"
	<< std::endl;
}

Fixed::Fixed(Fixed const &obj)
{
	std::cout
		<< "Copy constructor called"
	<< std::endl;
	*this = obj;
}

Fixed &	Fixed::operator=(Fixed const &obj)
{
	std::cout
		<< "Copy assignation operator called"
	<< std::endl;
	this->rawValue_ = obj.getRawBits();
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout
		<< "Destructor called"
	<< std::endl;
}

int	Fixed::getRawBits(void) const
{
	std::cout
		<< "getRawBits member function called"
	<< std::endl;
	return (this->rawValue_);
}

void	Fixed::setRawBits(int const raw)
{
	this->rawValue_ = raw;
}
