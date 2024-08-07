#include "day2.h"

int	ft_get_next_nb(char **str)
{
	int	i;
	int	res;

	if (!(*str))
		return (0);
	i = 0;
	while (!ft_isdigit(**str))
		(*str)++;
	res = 0;
	while (ft_isdigit(**str))
	{
		res = (res * 10) + (**str - '0');
		(*str)++;
	}
	return (res);
}

// int main(void)
// {
// 	char *str = "Game 5: 7 red, 7 green, 1 blue; 2 red, 1 green, 2 blue; 2 blue, 7 green; 7 red, 3 blue, 11 green";
// 	printf("%s\n", str);

// 	printf("id: %d\n", ft_get_next_nb(&str));
// 	printf("%s\n", str);

// 	printf("nb: %d\n", ft_get_next_nb(&str));
// 	printf("color: %c\n", ft_get_next_color(&str));
// 	printf("%s\n", str);

// 	printf("nb: %d\n", ft_get_next_nb(&str));
// 	printf("color: %c\n", ft_get_next_color(&str));
// 	printf("%s\n", str);

// 	printf("nb: %d\n", ft_get_next_nb(&str));
// 	printf("color: %c\n", ft_get_next_color(&str));
// 	printf("%s\n", str);

// 	printf("nb: %d\n", ft_get_next_nb(&str));
// 	printf("color: %c\n", ft_get_next_color(&str));
// 	printf("%s\n", str);
// 	return (0);
// }