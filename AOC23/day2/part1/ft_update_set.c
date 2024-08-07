#include "day2.h"

void	ft_update_set(t_set *set, char color, int nb)
{
	if (color == 'r')
		set->red = nb;
	else if (color == 'g')
		set->green = nb;
	else if (color == 'b')
		set->blue = nb;	
}