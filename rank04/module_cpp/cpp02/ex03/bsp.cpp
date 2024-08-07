/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 20:57:35 by momrane           #+#    #+#             */
/*   Updated: 2024/05/27 17:02:15 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed	getVectorProduct(Point const a, Point const b, Point const c)
{
	Fixed const	x1 = b.getX() - a.getX();
	Fixed const	y1 = b.getY() - a.getY();
	Fixed const	x2 = c.getX() - a.getX();
	Fixed const	y2 = c.getY() - a.getY();

	return (x1 * y2 - x2 * y1);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed const	a1 = getVectorProduct(a, b, point);
	Fixed const	a2 = getVectorProduct(b, c, point);
	Fixed const	a3 = getVectorProduct(c, a, point);

	if (point == a || point == b || point == c)
		return (false);
	return ((a1 > 0 && a2 > 0 && a3 > 0) || (a1 < 0 && a2 < 0 && a3 < 0));
}
