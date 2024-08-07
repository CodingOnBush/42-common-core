/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 12:08:11 by momrane           #+#    #+#             */
/*   Updated: 2023/11/22 11:18:34 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putnbr_hexa(unsigned long nbr, char format)
{
	unsigned long	long_min;
	unsigned long	ulong_max;
	int				count;
	char			*base;

	count = 0;
	long_min = LONG_MIN;
	ulong_max = ULONG_MAX;
	if (nbr == long_min)
		return (ft_print_string("8000000000000000"));
	else if (nbr == ulong_max && format == 'X')
		return (ft_print_string("FFFFFFFFFFFFFFFF"));
	else if (nbr == ulong_max && format == 'x')
		return (ft_print_string("ffffffffffffffff"));
	if (format == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (nbr >= 16)
		count += ft_putnbr_hexa(nbr / 16, format);
	count += ft_putchar(base[nbr % 16]);
	return (count);
}
