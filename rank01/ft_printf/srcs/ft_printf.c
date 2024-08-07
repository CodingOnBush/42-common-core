/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 12:07:04 by momrane           #+#    #+#             */
/*   Updated: 2023/11/24 07:05:29 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_print_format(char format, va_list *args, int *counter)
{
	*counter += 2;
	if (format == '%')
		return (ft_putchar('%'));
	else if (format == 'c')
		return (ft_putchar(va_arg(*args, int)));
	else if (ft_strchr("di", format))
		return (ft_print_integer(va_arg(*args, int), format));
	else if (format == 's')
		return (ft_print_string(va_arg(*args, char *)));
	else if (ft_strchr("uxX", format))
		return (ft_print_uinteger(va_arg(*args, unsigned int), format));
	else if (format == 'p')
		return (ft_print_ptr(va_arg(*args, void *)));
	*counter = *counter - 1;
	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		len_printed;
	int		i;

	va_start(args, s);
	len_printed = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
			len_printed += ft_print_format(s[i + 1], &args, &i);
		else
			len_printed += ft_putchar(s[i++]);
	}
	va_end(args);
	return (len_printed);
}

// #include <stdio.h>

// int main(void) {
// 	int result;

// 	//result = ft_printf("Hello, world!\n");
// 	//printf("Result: %d\n", result);

// 	//result = ft_printf("Le nombre %d est un entier.\n", 42);
// 	//printf("Result: %d\n", result);

// 	//result = ft_printf("%s, %d, %c\n", "Test", 123, 'A');
// 	//printf("Result: %d\n", result);

// 	// printf("printf:\n");
// 	// result = printf(" %p %p ", LONG_MIN, LONG_MAX);
// 	// printf("Result: %d\n", result);
// 	// result = printf(" %p %p ", ULONG_MAX, -ULONG_MAX);
// 	// printf("Result: %d\n", result);

// 	// printf("ft_printf:\n");
// 	result = ft_printf(" %p %p ", NULL, NULL);
// 	printf("Result: %d\n", result);
// 	result = printf(" %p %p ", NULL, NULL);
// 	printf("Result: %d\n", result);

// 	return (0);
// }