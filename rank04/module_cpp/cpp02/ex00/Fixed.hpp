/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:49:57 by momrane           #+#    #+#             */
/*   Updated: 2024/05/27 16:58:31 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

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
};

#endif