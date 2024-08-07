#include "day3.h"

void	ft_fill_map(char **map)
{
	int		fd;
	char	*line;
	int		i;

	fd = open("input.txt", O_RDONLY);
	if (fd == -1)
		return ;
	i = 0;
	while (i < LINE)
	{
		if ((line = get_next_line(fd)) == NULL)
		{
			close(fd);
			free(line);
			return ;
		}
		map[i] = line;
		i++;
	}
	close(fd);
}
