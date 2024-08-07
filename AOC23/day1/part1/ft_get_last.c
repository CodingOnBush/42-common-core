#include "day1.h"

int	ft_get_last(char *line)
{
	int	i;
	int	last;

	i = 0;
	last = -1;
	while (line[i])
	{
		if (ft_isdigit(line[i]))
			last = line[i] - '0';
		i++;
	}
	return (last);
}