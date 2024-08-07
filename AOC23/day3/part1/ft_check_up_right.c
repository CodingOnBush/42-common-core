#include "day3.h"

int	ft_check_up_right(char **map, int i, int j)
{
	if (i == 0 || map[i - 1][j + 1] == '\0')
		return (0);
	if (ft_is_symbol(map[i - 1][j + 1]))
		return (1);
	return (0);
}