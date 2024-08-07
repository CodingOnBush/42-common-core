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
		static const int	fractionalBits_ = 8;

	public:
		Fixed(void);
		Fixed(const Fixed &obj);
		Fixed &	operator=(const Fixed &obj);
		
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
		
		~Fixed(void);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		Fixed(const int value);
		Fixed(const float value);

		float	toFloat(void) const;
		int		toInt(void) const;

		static Fixed &			min(Fixed &a, Fixed &b);	// return the smallest of the two
		static const Fixed &	min(const Fixed &a, const Fixed &b);	// return the smallest of the two
		static Fixed &			max(Fixed &a, Fixed &b);	// return the biggest of the two
		static const Fixed &	max(const Fixed &a, const Fixed &b);	// return the biggest of the two
};

std::ostream &	operator<<(std::ostream &o, const Fixed &obj);

#endif