#include "day3.h"

int	check_up(char **map, int line, int col)
{
	if (line == LINE)
		return (0);
	if (col == 0)
	{
		if (ft_isdigit(map[line - 1][col]))
			return (1);
		if (ft_isdigit(map[line - 1][col + 1]))
			return (1);
		return (0);
	}
	if (ft_isdigit(map[line - 1][col]))
		return (1);
	if (ft_isdigit(map[line - 1][col + 1]) && ft_isdigit(map[line - 1][col - 1]))
		return (2);
	if (ft_isdigit(map[line - 1][col + 1]) || ft_isdigit(map[line - 1][col - 1]))
		return (1);
	return (0);
}
