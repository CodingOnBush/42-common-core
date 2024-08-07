/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:14:56 by momrane           #+#    #+#             */
/*   Updated: 2023/11/23 11:23:07 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_print_second_part(unsigned long ptr)
{
	unsigned long	long_min;
	unsigned long	ulong_max;
	int				count;

	count = 0;
	long_min = LONG_MIN;
	ulong_max = ULONG_MAX;
	if (ptr == long_min)
		return (ft_print_string("8000000000000000"));
	else if (ptr == ulong_max)
		return (ft_print_string("ffffffffffffffff"));
	if (ptr >= 16)
		count += ft_print_second_part(ptr / 16);
	count += ft_putchar("0123456789abcdef"[ptr % 16]);
	return (count);
}

int	ft_print_ptr(void *ptr)
{
	int	count;

	count = 0;
	if (ptr == NULL)
		return (ft_print_string("(nil)"));
	if ((unsigned long)ptr == 0)
		return (ft_print_string("0x0"));
	count += ft_print_string("0x");
	count += ft_print_second_part((unsigned long)ptr);
	return (count);
}

// #include <stdio.h>

// int	main(void)
// {
// 	ft_printf(" %p %p \n", 0, 0);
// 	return (0);
// }