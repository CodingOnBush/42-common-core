#include "day3.h"

int	ft_check_down(char **map, int i, int j)
{
	if (i == LINE - 1)
		return (0);
	if (ft_is_symbol(map[i + 1][j]))
		return (1);
	return (0);
}