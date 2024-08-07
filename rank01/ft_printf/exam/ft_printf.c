#include <unistd.h>
#include <stdarg.h>

void	put_string(char *string, int *length)
{
	if (!string)
		string = "(null)";
	while (*string)
		*length += write(1, string++, 1);
}

void	put_digit(long long int number, int base, int *length)
{
	char	*hexadecimal = "0123456789abcdef";

	if (number < 0)
	{
		number *= -1;
		*length += write(1, "-", 1);
	}
	if (number >= base)
		put_digit((number / base), base, length);
	*length += write(1, &hexadecimal[number % base], 1);
}

int	ft_printf(const char *str, ...)
{
	int length = 0;

	va_list	pointer;
	va_start(pointer, str);

	while (*str)
	{
		if ((*str == '%') && ((*(str + 1) == 's') || (*(str + 1) == 'd') || (*(str + 1) == 'x')))
		{
			str++;
			if (*str == 's')
				put_string(va_arg(pointer, char *), &length);
			else if (*str == 'd')
				put_digit((long long int)va_arg(pointer, int), 10, &length);
			else if (*str == 'x')
				put_digit((long long int)va_arg(pointer, unsigned int), 16, &length);
		}
		else
			length += write(1, str, 1);
		str++;
	}
	va_end(pointer);
	return (length);
}
