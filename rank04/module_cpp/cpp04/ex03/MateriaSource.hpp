/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 09:07:18 by momrane           #+#    #+#             */
/*   Updated: 2024/06/12 17:26:34 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria *_inventory[4]; // Inventory of AMateria

public:
	MateriaSource();									// Default constructor
	MateriaSource(MateriaSource const &obj);			// Copy constructor
	MateriaSource &operator=(MateriaSource const &obj); // Copy assignment operator
	virtual ~MateriaSource();							// Destructor

	virtual void learnMateria(AMateria *m);					  // From IMateriaSource
	virtual AMateria *createMateria(std::string const &type); // From IMateriaSource
};

#endif