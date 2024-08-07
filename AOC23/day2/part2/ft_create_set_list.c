#include "day2.h"

t_set *ft_create_set_list(char *line)
{
	int	i;
	int	nb;
	int	id;
	int	color;
	t_set	*newset;
	t_set	*lst;

	i = 0;
	nb = 0;
	id = ft_get_next_nb(&line);
	lst = NULL;
	while (*line != '\0' && *line != '\n')
	{
		newset = malloc(sizeof(t_set));
		if (!newset)
			return (0);
		newset->blue = 0;
		newset->red = 0;
		newset->green = 0;
		newset->next = NULL;
		while (*line != ';' && *line != '\0' && *line != '\n')
		{
			nb = ft_get_next_nb(&line);
			color = ft_get_next_color(&line);
			ft_update_set(newset, color, nb);
		}
		if (*line == ';')
			line++;
		ft_add_set(&lst, newset);
		// printf("newset->blue: %d\n", newset->blue);
		// printf("newset->red: %d\n", newset->red);
		// printf("newset->green: %d\n\n", newset->green);
		// printf("*line: %c (%d)\n", *line, *line);
	}
	// ft_print_lst(lst);
	return (lst);
}

// int	main(void)
// {
// 	char	*line;

// 	line = malloc(sizeof(char) * 200);
// 	if (!line)
// 		return (0);
// 	line = "Game 5: 7 red, 99 green, 1 blue; 2 red, 1 green, 2 blue; 2 blue, 7 green; 7 red, 3 blue, 11 green\0";
// 	printf("line: %s\n", line);

// 	ft_get_power(line);
// 	return (0);
// }