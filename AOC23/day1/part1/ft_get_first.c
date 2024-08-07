#include "day1.h"

int	ft_get_first(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (ft_isdigit(line[i]))
			return (line[i] - '0');
		i++;
	}
	return (-1);
}