#include "day2.h"

int	ft_is_valid_set(t_set *set)
{
	if ((set->red <= RED) && (set->green <= GREEN) && (set->blue <= BLUE))
		return (1);
	return (0);
}