#include "day2.h"

int	ft_is_game_valid(char *line)
{
	int	i;
	int	nb;
	int	id;
	int	color;
	t_set	*set;

	i = 0;
	id = ft_get_next_nb(&line);
	printf("id: %d\n", id);
	nb = 0;
	while (*line != '\0' && *line != '\n')
	{
		set = malloc(sizeof(t_set));
		if (!set)
			return (0);
		set->blue = 0;
		set->red = 0;
		set->green = 0;
		while (*line != ';' && *line != '\0' && *line != '\n')
		{
			nb = ft_get_next_nb(&line);
			color = ft_get_next_color(&line);
			ft_update_set(set, color, nb);
			if (!ft_is_valid_set(set))
			{
				free(set);
				return (0);
			}
			if (*line == ';')
				line++;
			printf("yo\n");
			printf("set->blue: %d\n", set->blue);
			printf("set->red: %d\n", set->red);
			printf("set->green: %d\n", set->green);
			printf("*line: %d\n", *line);
		}
		free(set);
	}
	return (id);
}

// int	main(void)
// {
// 	char	*line;
// 	int		valid;
	
// 	line = malloc(sizeof(char) * 100);
// 	if (!line)
// 		return (0);
// 	line = "Game 5: 7 red, 99 green, 1 blue; 2 red, 1 green, 2 blue; 2 blue, 7 green; 7 red, 3 blue, 11 green";
// 	printf("line: %s\n", line);
// 	// printf("indx: %s\n", indx);
// 	valid = ft_is_game_valid(line);
// 	printf("valid: %d\n", valid);
// 	return (0);
// }