/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 16:36:17 by momrane           #+#    #+#             */
/*   Updated: 2023/11/22 11:18:41 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_print_integer(int n, char format)
{
	int			count;
	long int	nb;

	count = 0;
	nb = (long int)n;
	if (nb < 0)
	{
		count += ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
	{
		count += ft_print_integer(nb / 10, format);
		count += ft_putchar(nb % 10 + '0');
	}
	else
		count += ft_putchar(nb + '0');
	return (count);
}
