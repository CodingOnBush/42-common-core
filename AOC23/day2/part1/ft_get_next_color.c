#include "day2.h"

char	ft_get_next_color(char **str)
{
	char	res;

	if (!(*str))
		return (0);
	while (*(*str) != 'r' && *(*str) != 'g' && *(*str) != 'b' && *(*str))
		*str = *str + 1;
	res = *(*str);
	switch (res)
	{
		case 'r':
			*str += 3;
			break;
		case 'g':
			*str += 5;
			break;
		case 'b':
			*str += 4;
			break;
		default:
			res = 'X';
			break;
	}
	return (res);
}

// int main(void)
// {
// 	// char str[100] = " red, 7 green, 1 blue; 2 red, 1 green, 2 blue; 2 blue, 7 green; 7 red, 3 blue, 11 green";
// 	char *str;

// 	str = malloc(sizeof(char) * 100);
// 	if (!str)
// 		return (0);
// 	str = "8 red;";
// 	printf("str: %s\n", str);
// 	printf("res: %c\n", ft_get_next_color(&str));
// 	printf("str: %s\n", str);
// 	printf("res: %c\n", ft_get_next_color(&str));
// 	printf("str: %s\n", str);
// 	return (0);
// }