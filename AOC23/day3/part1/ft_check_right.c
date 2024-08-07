#include "day3.h"

int	ft_check_right(char **map, int i, int j)
{
	if (map[i][j] == '\0' || map[i][j] == '\n')
		return (0);
	if (map[i][j + 1] == '\0')
		return (0);
	if (ft_is_symbol(map[i][j + 1]))
		return (1);
	return (0);
}