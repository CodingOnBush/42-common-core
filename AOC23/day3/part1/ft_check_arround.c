#include "day3.h"

int	ft_check_around(char **map, int i, int j)
{
	while (ft_isdigit(map[i][j]) && map[i][j] != '\0')
	{
		if (ft_check_right(map, i, j))
			return (1);
		if (ft_check_down_right(map, i, j))
			return (1);
		if (ft_check_down(map, i, j))
			return (1);
		if (ft_check_down_left(map, i, j))
			return (1);
		if (ft_check_left(map, i, j))
			return (1);
		if (ft_check_up_left(map, i, j))
			return (1);
		if (ft_check_up(map, i, j))
			return (1);
		if (ft_check_up_right(map, i, j))
			return (1);
		j++;
	}
	return (0);
}