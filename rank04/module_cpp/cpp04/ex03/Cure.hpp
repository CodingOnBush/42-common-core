/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 08:50:12 by momrane           #+#    #+#             */
/*   Updated: 2024/06/03 11:26:03 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure();
		Cure(Cure const & obj);
		Cure & operator=(Cure const & obj);
		virtual ~Cure();
		
		AMateria*	clone(void) const;
		void		use(ICharacter& target);
};

#endif