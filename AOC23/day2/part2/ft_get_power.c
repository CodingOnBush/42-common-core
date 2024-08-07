#include "day2.h"

int	ft_get_power(t_set *lst)
{
	int		res;
	t_set	*current;
	t_set	*fewest;

	res = 0;
	current = lst;
	ft_print_lst(current);
	fewest = malloc(sizeof(t_set));
	if (!fewest)
		return (0);
	fewest->blue = 0;
	fewest->red = 0;
	fewest->green = 0;
	fewest->next = NULL;
	while (current != NULL)
	{
		if (current->red > fewest->red)
			fewest->red = current->red;
		if (current->green > fewest->green)
			fewest->green = current->green;
		if (current->blue > fewest->blue)
			fewest->blue = current->blue;
		current = current->next;
	}
	// printf("fewest->blue: %d\n", fewest->blue);
	// printf("fewest->red: %d\n", fewest->red);
	// printf("fewest->green: %d\n\n", fewest->green);
	res = fewest->red * fewest->green * fewest->blue;
	return (res);
}
