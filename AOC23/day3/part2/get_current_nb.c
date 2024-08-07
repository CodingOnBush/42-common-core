#include "day3.h"

long	get_current_nb(char **map, int line, int col)
{
	long	nb;

	nb = -1;
	if (check_current(map, line, col) == 0)
		return (-1);
	if (col == 0)
		return (ft_get_full_nb(map, line, col + 1));
	else
	{
		nb = 1;
		if (ft_isdigit(map[line][col + 1]))
			nb *= ft_get_full_nb(map, line, col + 1);
		if (ft_isdigit(map[line][col - 1]))
			nb *= ft_get_full_nb(map, line, col - 1);
	}
	return (nb);
}