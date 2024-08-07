#include "Point.hpp"

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 20:57:48 by momrane           #+#    #+#             */
/*   Updated: 2024/05/18 20:57:49 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : x_(0), y_(0)
{
}

Point::Point(const float x, const float y) :
	x_(Fixed(x)),
	y_(Fixed(y))
{
}

Point::Point(const Point &obj) :
	x_(obj.x_),
	y_(obj.y_)
{
}

Point &Point::operator=(const Point &obj)
{
	(void)obj;
	return (*this);
}

bool Point::operator==(const Point &obj) const
{
	if (x_ == obj.x_ && y_ == obj.y_)
		return (true);
	return (false);
}

Point::~Point(void)
{
}

const Fixed	Point::getX(void) const
{
	return (x_);
}

const Fixed	Point::getY(void) const
{
	return (y_);
}

std::ostream &	operator<<(std::ostream &o, Point const &obj)
{
	o << "Point(" << obj.getX() << ", " << obj.getY() << ")";
	return (o);
}

