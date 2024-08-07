/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:59:24 by momrane           #+#    #+#             */
/*   Updated: 2024/06/12 18:35:02 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"


static void	test1(void)
{
	std::cout << RED << "Let's create a ptr Animal : " << RESET << std::endl;
	const Animal*	ptrAnimal = new Animal();

	std::cout << std::endl;

	std::cout << RED << "Let's create a Dog and a Cat : " << RESET << std::endl;
	const Animal*	dog = new Dog();
	const Animal*	cat = new Cat();

	std::cout << std::endl;

	std::cout << "════════════════════════════════════════" << std::endl;
	ptrAnimal->makeSound();
	dog->makeSound();
	cat->makeSound();
	std::cout << "════════════════════════════════════════" << std::endl;

	std::cout << std::endl;

	std::cout << RED << "Let's delete the Dog and the Cat: " << RESET << std::endl;
	delete dog;
	delete cat;
	
	std::cout << std::endl;

	std::cout << RED << "Let's delete the ptr Animal: " << RESET << std::endl;
	delete ptrAnimal;
}

static void	test2(void)
{
	std::cout << RED << "Let's create a ptr Animal : " << RESET << std::endl;
	const WrongAnimal*	ptrAnimal = new WrongAnimal();

	std::cout << std::endl;

	std::cout << RED << "Let's create a WrongCat : " << RESET << std::endl;
	const WrongAnimal*	cat = new WrongCat();

	std::cout << std::endl;

	std::cout << "════════════════════════════════════════" << std::endl;
	ptrAnimal->makeSound();
	cat->makeSound();
	std::cout << "════════════════════════════════════════" << std::endl;

	std::cout << std::endl;

	std::cout << RED << "Let's delete the WrongCat: " << RESET << std::endl;
	delete cat;
	
	std::cout << std::endl;

	std::cout << RED << "Let's delete the ptr WrongAnimal: " << RESET << std::endl;
	delete ptrAnimal;
}

static void	subsjectTest(void)
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << meta->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	// ...
	
	delete j;
	delete i;
	delete meta;
}

int main(void)
{
	subsjectTest();
	std::cout << std::endl;
	std::cout << "════════════════════════════════════════════════════════════════════════════════" << std::endl;
	std::cout << std::endl;
	test1();
	std::cout << std::endl;
	std::cout << "════════════════════════════════════════════════════════════════════════════════" << std::endl;
	std::cout << std::endl;
	test2();
	return (0);
}
