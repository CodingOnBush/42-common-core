#include "day3.h"

int	check_current(char **map, int line, int col)
{
	if (col == 0)
	{
		if (ft_isdigit(map[line][col + 1]))
			return (1);
		return (0);
	}
	if (ft_isdigit(map[line][col + 1]) && ft_isdigit(map[line][col - 1]))
		return (2);
	if (ft_isdigit(map[line][col + 1]) || ft_isdigit(map[line][col - 1]))
		return (1);
	return (0);
}