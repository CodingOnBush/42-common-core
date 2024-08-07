/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allblue <allblue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:49:57 by momrane           #+#    #+#             */
/*   Updated: 2024/06/12 09:48:26 by allblue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int					rawValue_;
		int static const	fractionalBits_ = 8;

	public:
		Fixed(void);							// Default constructor
		Fixed(Fixed const &obj);				// Copy constructor
		Fixed &	operator=(Fixed const &obj);	// Assignation operator
		~Fixed(void);							// Destructor

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		Fixed(int const value);
		Fixed(float const value);

		float	toFloat(void) const;
		int		toInt(void) const;
	
		bool	operator>(const Fixed &obj) const;
		bool	operator<(const Fixed &obj) const;
		bool	operator>=(const Fixed &obj) const;
		bool	operator<=(const Fixed &obj) const;
		bool	operator==(const Fixed &obj) const;
		bool	operator!=(const Fixed &obj) const;
		
		Fixed	operator+(const Fixed &obj) const;
		Fixed	operator-(const Fixed &obj) const;
		Fixed	operator*(const Fixed &obj) const;
		Fixed	operator/(const Fixed &obj) const;
		
		Fixed &	operator++(void);
		Fixed	operator++(int);
		Fixed &	operator--(void);
		Fixed	operator--(int);

		static Fixed &			min(Fixed &a, Fixed &b);
		static const Fixed &	min(const Fixed &a, const Fixed &b);
		static Fixed &			max(Fixed &a, Fixed &b);
		static const Fixed &	max(const Fixed &a, const Fixed &b);
};

std::ostream &	operator<<(std::ostream &o, Fixed const &obj);

#endif