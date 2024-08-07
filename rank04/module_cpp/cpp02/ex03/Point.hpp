/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 20:57:51 by momrane           #+#    #+#             */
/*   Updated: 2024/05/27 16:58:31 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	private:
		Fixed const x_;
		Fixed const y_;
	
	public:
		Point(void);							// default constructor
		Point(Point const &obj);				// copy constructor
		Point &	operator=(Point const &obj);	// assignation operator
		~Point(void);							// destructor
		
		Point(float const x, float const y);
		bool	operator==(Point const &obj) const;
		
		const Fixed	getX(void) const;
		const Fixed	getY(void) const;
};

std::ostream &	operator<<(std::ostream &o, Point const &obj);
bool			bsp(Point const a, Point const b, Point const c, Point const point);

#endif