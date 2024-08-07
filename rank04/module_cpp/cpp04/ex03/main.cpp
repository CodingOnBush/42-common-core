/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:59:24 by momrane           #+#    #+#             */
/*   Updated: 2024/06/12 18:31:50 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

static void testSubject(void)
{
	std::cout << "\nRUNNNING SUBJECT TESTS\n"
			  << std::endl;
	IMateriaSource *src = new MateriaSource();

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter *me = new Character("me");
	AMateria *tmp;

	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("unknown");
	ICharacter *bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
}

static void testCharacter(void)
{
	std::cout << "\nTESTING CHARACTER OBJECT\n"
			  << std::endl;
	ICharacter *player1 = new Character("Player 1");
	ICharacter *player2 = new Character("Player 2");
	AMateria *ice = new Ice();

	/* Filling Player 1's inventory */
	player1->equip(new Ice());
	player1->equip(ice);
	player1->equip(new Ice());
	player1->equip(new Cure());
	// player1->equip(new Cure()); // Over filling Player 1's inventory

	/* Filling Player 2's inventory */
	player2->equip(new Cure());
	player2->equip(new Cure());
	player2->equip(new Ice());

	/* Using materias */
	player1->use(0, *player2);
	player1->use(1, *player2);
	player1->use(3, *player2);
	player2->use(2, *player1);

	/* Unequiping materia and use empty slot */
	player1->unequip(1);
	player1->use(1, *player2);

	/* Equiping new materia and use the filled slot */
	player1->equip(new Cure());
	player1->use(1, *player2);

	delete player1;
	delete player2;
	delete ice;
}

static void testMateriaSource()
{
	std::cout << "\nTESTING MATERIASOURCE OBJECT\n"
			  << std::endl;
	IMateriaSource *materiaSource = new MateriaSource();
	ICharacter *player1 = new Character("Player 1");
	ICharacter *player2 = new Character("Player 2");

	/* Learning new materias */
	materiaSource->learnMateria(new Ice());
	materiaSource->learnMateria(new Cure());
	materiaSource->learnMateria(new Cure());
	materiaSource->learnMateria(new Cure());
	// materiaSource->learnMateria(new Cure()); // Over learning items

	/* Equiping learnt materias */
	player1->equip(materiaSource->createMateria("cure"));
	player1->equip(materiaSource->createMateria("cure"));
	player1->equip(materiaSource->createMateria("ice"));
	player1->equip(materiaSource->createMateria("ice"));
	// player1->equip(materiaSource->createMateria("cure")); // Over filling Player 1's inventory

	player1->use(0, *player2);
	player1->use(2, *player2);

	delete materiaSource;
	delete player1;
	delete player2;
}

static void testOperator()
{
	Character *me = new Character("mostafa");
	Character *clone = new Character(*me);

	std::cout << "me 	: " << me->getName() << std::endl;
	std::cout << "clone	: " << clone->getName() << std::endl;

	*me = *clone;
	*clone = *me;

	delete me;
	delete clone;
}

int main(void)
{
	testSubject();
	testCharacter();
	testMateriaSource();
	testOperator();
	return (0);
}
