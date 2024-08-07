/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uinteger.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:15:45 by momrane           #+#    #+#             */
/*   Updated: 2023/11/22 11:19:14 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_print_uinteger(unsigned int nb, char format)
{
	int					count;
	unsigned long		n;

	if (format == 'x' || format == 'X')
		return (ft_putnbr_hexa(nb, format));
	count = 0;
	n = (unsigned long)nb;
	if (n >= 10)
		count += ft_print_uinteger(n / 10, format);
	count += ft_putchar((n % 10) + '0');
	return (count);
}

// #include <limits.h>

// int main()
// {
//     int number = 42;

//     char base_decimal[] = "0123456789";
//     char base_binary[] = "01";
//     char base_hexadecimal[] = "0123456789ABCDEF";

//     // Test with different bases
//     ft_putnbr_base(number, base_decimal);
//     ft_putchar('\n');

//     ft_putnbr_base(number, base_binary);
//     ft_putchar('\n');

//     ft_putnbr_base(number, base_hexadecimal);
//     ft_putchar('\n');

//     return 0;
// }