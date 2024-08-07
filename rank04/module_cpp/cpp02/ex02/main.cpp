/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allblue <allblue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:49:38 by momrane           #+#    #+#             */
/*   Updated: 2024/06/12 09:48:26 by allblue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

static void	printTitle(std::string title, int width)
{
	int	spaces = width - title.length() - 2;
	
	std::cout << "╔";
	for (int i = 0; i < width; i++)
		std::cout << "═";
	std::cout << "╗" << std::endl;
	std::cout << "║ " << title;
	for (int i = 0; i < spaces; i++)
		std::cout << " ";
	std::cout << " ║" << std::endl;
	std::cout << "╚";
	for (int i = 0; i < width; i++)
		std::cout << "═";
	std::cout << "╝" << std::endl;
}

static void	testComparisonOperators(void)
{
	Fixed a(10.5f);
	Fixed b(20.43f);
	Fixed c(10.5f);

	printTitle("OPERATEURS DE COMPARAISON", 42);
	
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "c = " << c << std::endl;

	std::cout << a << " > " << b << "  : " << ((a > b) ? "true" : "false") << std::endl;
	std::cout << a << " < " << b << "  : " << ((a < b) ? "true" : "false") << std::endl;
	std::cout << a << " >= " << b << " : " << ((a >= b) ? "true" : "false") << std::endl;
	std::cout << a << " <= " << b << " : " << ((a <= b) ? "true" : "false") << std::endl;
	std::cout << a << " == " << b << " : " << ((a == b) ? "true" : "false") << std::endl;
	std::cout << a << " != " << b << " : " << ((a != b) ? "true" : "false") << std::endl;
	std::cout << a << " == " << c << " : " << ((a == c) ? "true" : "false") << std::endl;
	std::cout << a << " != " << c << " : " << ((a != c) ? "true" : "false") << std::endl;
}

static void	testArithmeticOperators(void)
{
	Fixed a(10);
	Fixed b(20.123123f);
	Fixed c(Fixed(42.75f) / a);

	printTitle("OPERATEURS ARITHMETIQUES", 42);

	std::cout << "a = " << a << std::endl;	
	std::cout << "b = " << b << std::endl;
	std::cout << "c = " << c << std::endl;

	std::cout << a << " + " << b << " = " << (a + b) << std::endl;
	std::cout << b << " - " << a << " = " << (b - a) << std::endl;
	std::cout << a << " * " << b << " = " << (a * b) << std::endl;
	std::cout << b << " / " << a << " = " << (b / a) << std::endl;
	std::cout << a << " + " << c << " = " << (a + c) << std::endl;
	std::cout << b << " - " << c << " = " << (b - c) << std::endl;
	std::cout << a << " * " << c << " = " << (a * c) << std::endl;
	std::cout << b << " / " << c << " = " << (b / c) << std::endl;
}

static void	testIncrementDecrementOperators(void)
{
	Fixed a(10);
	Fixed b(10);
	Fixed c(10);
	Fixed d(10);
	
	printTitle("OPERATEURS D'INCRE/DECREMENTATION", 42);
	
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;

	std::cout << "a++ < b : " << ((a++ < b) ? "true" : "false") << std::endl;
	std::cout << "a = " << a << std::endl;
	
	std::cout << "c = " << c << std::endl;
	std::cout << "d = " << d << std::endl;

	std::cout << "++c < d : " << ((c++ < d) ? "true" : "false") << std::endl;
	std::cout << "c = " << c << std::endl;
	
	std::cout << "a = " << a << std::endl;
	std::cout << "++a = " << ++a << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "a++ = " << a++ << std::endl;
	std::cout << "a = " << a << std::endl;
	
	std::cout << "a > b : " << ((a > b) ? "true" : "false") << std::endl;
	std::cout << "a < b : " << ((a < b) ? "true" : "false") << std::endl;
	std::cout << "a >= b : " << ((a >= b) ? "true" : "false") << std::endl;
	std::cout << "a <= b : " << ((a <= b) ? "true" : "false") << std::endl;
	std::cout << "a == b : " << ((a == b) ? "true" : "false") << std::endl;
	std::cout << "a != b : " << ((a != b) ? "true" : "false") << std::endl;
	std::cout << "a == c : " << ((a == c) ? "true" : "false") << std::endl;
	std::cout << "a != c : " << ((a != c) ? "true" : "false") << std::endl;

	std::cout << "b = " << b << std::endl;
	std::cout << "--b = " << --b << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "b-- = " << b-- << std::endl;
	std::cout << "b = " << b << std::endl;
	
	std::cout << "b > c : " << ((b > c) ? "true" : "false") << std::endl;
	std::cout << "b < c : " << ((b < c) ? "true" : "false") << std::endl;
	std::cout << "b >= c : " << ((b >= c) ? "true" : "false") << std::endl;
	std::cout << "b <= c : " << ((b <= c) ? "true" : "false") << std::endl;
	std::cout << "b == c : " << ((b == c) ? "true" : "false") << std::endl;
}

static void	testFindMinMax(void)
{
	Fixed a(10);
	Fixed b(20.787878f);
	Fixed c(Fixed(42.75f) / a);

	printTitle("FIND MIN/MAX", 42);

	std::cout << "a = " << a << std::endl;	
	std::cout << "b = " << b << std::endl;
	std::cout << "c = " << c << std::endl;

	std::cout << "min(a, b) = " << Fixed::min(a, b) << std::endl;
	std::cout << "max(a, b) = " << Fixed::max(a, b) << std::endl;
	std::cout << "min(b, c) = " << Fixed::min(b, c) << std::endl;
	std::cout << "max(b, c) = " << Fixed::max(b, c) << std::endl;
	std::cout << "max(b, b) = " << Fixed::max(b, b) << std::endl;
}

static void	testFromSubject(void)
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));

	printTitle("FROM SUBJECT", 42);
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;
}

int main(void)
{
	testFromSubject();	
	testComparisonOperators();
	testArithmeticOperators();
	testIncrementDecrementOperators();
	testFindMinMax();
	return (0);
}
