#include "day3.h"

long	ft_get_full_nb(char **map, int i, int j)
{
	long	res;

	if (!map || !*map)
		return (0);
	while (j > 0 && ft_isdigit(map[i][j]))
		j--;
	res = 0;
	while (!ft_isdigit(map[i][j]) && map[i][j] != '\0')
		j++;
	while (ft_isdigit(map[i][j]) && map[i][j] != '\0')
	{
		res = (res * 10) + (map[i][j] - '0');
		j++;
	}
	return (res);
}

// int main(void)
// {
// 	char *str = "...254...";
// 	printf("%s\n", str);

// 	printf("nb: %d\n", ft_get_full_nb(&str, 0, 6));

// 	return (0);
// }