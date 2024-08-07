#include "day3.h"

long	get_down_nb(char **map, int line, int col)
{
	long	nb;

	nb = -1;
	if (line == LINE || check_down(map, line, col) == 0)
		return (-1);
	if (col == 0)
		return (ft_get_full_nb(map, line + 1, col));
	if (ft_isdigit(map[line + 1][col]))
		return (ft_get_full_nb(map, line + 1, col - 1));
	else
	{
		nb = 1;
		if (ft_isdigit(map[line + 1][col + 1]))
			nb *= ft_get_full_nb(map, line + 1, col + 1);
		if (ft_isdigit(map[line + 1][col - 1]))
			nb *= ft_get_full_nb(map, line + 1, col - 1);
	}
	return (nb);
}