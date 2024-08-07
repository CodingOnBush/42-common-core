#include "day3.h"

int	ft_atoi(char **map, int i, int j)
{
	int	res;

	if (!map || !*map)
		return (0);
	while (!ft_isdigit(map[i][j]) && map[i][j] != '\0')
		j++;
	res = 0;
	while (ft_isdigit(map[i][j]) && map[i][j] != '\0')
	{
		res = (res * 10) + (map[i][j] - '0');
		j++;
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