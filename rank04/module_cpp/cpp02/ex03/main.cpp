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
#include "Point.hpp"

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
	
	std::cout << "Fixed a(10.5f)  -> " << a << std::endl;
	std::cout << "Fixed b(20.43f) -> " << b << std::endl;
	std::cout << "Fixed c(10.5f)  -> " << c << std::endl << std::endl;

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

	std::cout << "Fixed a(10)                -> " << a << std::endl;	
	std::cout << "Fixed b(20.123123f)        -> " << b << std::endl;
	std::cout << "Fixed c(Fixed(42.75f) / a) -> " << c << std::endl << std::endl;

	std::cout << a << "\t+ " << b << "  = " << (a + b) << std::endl;
	std::cout << b << "\t- " << a << "   \t= " << (b - a) << std::endl;
	std::cout << a << "\t* " << b << " = " << (a * b) << std::endl;
	std::cout << b << "\t/ " << a << "   \t= " << (b / a) << std::endl;
	std::cout << a << "\t+ " << c << "    \t= " << (a + c) << std::endl;
	std::cout << b << "\t- " << c << "    \t= " << (b - c) << std::endl;
	std::cout << a << "\t* " << c << "    \t= " << (a * c) << std::endl;
	std::cout << b << "\t/ " << c << "    \t= " << (b / c) << std::endl;
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

static void	testBSP(void)
{
	Point	a(2.0f, 3.0f);
	Point	b(6.0f, 4.0f);
	Point	c(3.0f, 7.0f);
	Point	x(5.0f, 5.0f);
	Point	z(5.0f, 2.0f);
	Point	y(4.0f, 5.0f);

	printTitle("BSP", 42);

	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "c = " << c << std::endl;
	std::cout << "x = " << x << std::endl;
	std::cout << "z = " << z << std::endl;
	std::cout << "y = " << y << std::endl;
	
	std::cout << "Let's check if x is inside the triangle abc" << std::endl;
	std::cout << "bsp(a, b, c, x) = " << (bsp(a, b, c, x) ? "true" : "false") << std::endl << std::endl;
	std::cout << "Let's check if z is inside the triangle abc" << std::endl;
	std::cout << "bsp(a, b, c, z) = " << (bsp(a, b, c, z) ? "true" : "false") << std::endl << std::endl;
	std::cout << "Let's check if y is inside the triangle abc" << std::endl;
	std::cout << "bsp(a, b, c, y) = " << (bsp(a, b, c, y) ? "true" : "false") << std::endl << std::endl;
}

int main(void)
{
	testComparisonOperators();
	testArithmeticOperators();
	testIncrementDecrementOperators();
	testFindMinMax();
	testBSP();
	return (0);
}
