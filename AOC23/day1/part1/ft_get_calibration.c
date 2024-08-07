#include "day1.h"

int	ft_get_calibration(char *line)
{
	int	res;

	res = ft_get_first(line);
	if (res == -1)
		return (0);
	res = (res * 10) + ft_get_last(line);
	return (res);
}