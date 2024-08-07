#include "day3.h"

void	ft_print_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (i < LINE)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			printf("%c", map[i][j]);
			j++;
		}
		i++;
	}
}

int	main(void)
{
	char	**map;
	int		i;
	int		j;
	int		res;
	int		nb;

	map = (char **)malloc(sizeof(char *) * (LINE + 1));
	if (!map)
		return (1);
	map[LINE] = NULL;
	ft_fill_map(map);
	i = 0;
	res = 0;
	while (i < LINE)
	{
		j = 0;
		// printf("\n\n%s", map[i]);
		printf("[i = %d] : ", i + 1);
		while (map[i][j] != '\0')
		{
			// printf("j = %d\n", j);
			if (ft_isdigit(map[i][j]))
			{
				// printf("map[%d][%d] = %c\n", i, j, map[i][j]);
				nb = ft_atoi(map, i, j);
				if (ft_check_around(map, i, j) == 1)
				{
					// printf("res = %d\n", res);
					printf("[%d]", nb);
					res += nb;
				}
				j += ft_get_nb_len(nb);
			}
			else
				j++;
		}
		printf("\n");
		i++;
	}
	printf("\nres = %d\n", res);
	return (0);
}

/*
tentative 1 : 525120

*/