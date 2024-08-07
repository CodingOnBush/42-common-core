#include "day3.h"

int	ft_check_left(char **map, int i, int j)
{
	if (j == 0)
		return (0);
	if (ft_is_symbol(map[i][j - 1]))
		return (1);
	return (0);
}