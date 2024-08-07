#include "day1.h"

int	ft_get_nb(char *line)
{
	if (ft_strnstr(line, "one", 3) == 1)
		return (1);
	else if (ft_strnstr(line, "two", 3) == 1)
		return (2);
	else if (ft_strnstr(line, "three", 5) == 1)
		return (3);
	else if (ft_strnstr(line, "four", 4) == 1)
		return (4);
	else if (ft_strnstr(line, "five", 4) == 1)
		return (5);
	else if (ft_strnstr(line, "six", 3) == 1)
		return (6);
	else if (ft_strnstr(line, "seven", 5) == 1)
		return (7);
	else if (ft_strnstr(line, "eight", 5) == 1)
		return (8);
	else if (ft_strnstr(line, "nine", 4) == 1)
		return (9);
	return (-1);
}