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

long	get_result(char **map)
{
	long	out;
	int	i;
	int	j;
	long	tmp;

	out = 0;
	i = 0;
	j = 0;
	tmp = 0;
	int up;
	int down;
	int current;

	// printf("\n[%c] -> get_current_nb(map, %d, %d) : %d\n",map[i][j] ,i ,j , get_current_nb(map, i, j));
	while (i < LINE)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			up = -1;
			down = -1;
			current = -1;
			tmp = 0;
			if (map[i][j] == '*')
			{
				// up = get_up_nb(map, i, j);
				// down = get_down_nb(map, i, j);
				// current = get_current_nb(map, i, j);
				// if (up != -1 && down != -1 && current != -1)
				// 	out += 0;
				
				// out += tmp;
				if (check_up(map, i, j) + check_current(map, i, j) + check_down(map, i, j) == 2)
				{
					up = get_up_nb(map, i, j);
					down = get_down_nb(map, i, j);
					current = get_current_nb(map, i, j);
					printf("up : %d\ndown : %d\ncurrent : %d\n", up, down, current);
					printf("check_up : %d\n", check_up(map, i, j));
					printf("check_current : %d\n", check_current(map, i, j));
					printf("check_down : %d\n", check_down(map, i, j));
					if (up != -1 || down != -1 || current != -1)
					{
						tmp = 1;
						if (up != -1)
							tmp *= up;
						if (down != -1)
							tmp *= down;
						if (current != -1)
							tmp *= current;
						out += tmp;
					}
				}

				// printf("check_up : %d\n", check_up(map, i, j));
				// printf("check_current : %d\n", check_current(map, i, j));
				// printf("check_down : %d\n", check_down(map, i, j));
			}
			j++;
		}
		printf("[%ld] : %s", tmp, map[i]);
		i++;
	}
	return (out);
}

int	main(void)
{
	char	**map;
	int		i;
	int		j;
	long		res;
	int		nb;

	map = (char **)malloc(sizeof(char *) * (LINE + 1));
	if (!map)
		return (1);
	map[LINE] = NULL;
	ft_fill_map(map);
	// ft_print_map(map);
	res = get_result(map);
	printf("\nres = %ld\n", res);
	
	i = 0;
	while (i < LINE)
	{
		free(map[i]);
		i++;
	}
	free(map);
	return (0);
}

/*
tentative 1 : 525120
tentative 2 : 587405
tentative 3 : 459983
tentative 4 : 52263075
tentative 5 : 56820871
tentative 6 : 76504829
*/