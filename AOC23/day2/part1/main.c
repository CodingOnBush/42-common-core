#include "day2.h"

int	main(void)
{
	int		fd;
	char	*line;
	int		res;

	fd = open("input", O_RDONLY);
	if (fd < 0)
		return (0);
	res = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		res += ft_is_game_valid(line);
		free(line);
	}
	printf("Result: %d\n", res);
	return (0);
}