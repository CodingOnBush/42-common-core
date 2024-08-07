#include "day1.h"

int	main(void)
{
	int		fd;
	char	*line;
	int		res;
	int		i;
	int		j;

	fd = open("input_part2", O_RDONLY);
	if (fd == -1)
		return (0);
	res = 0;
	i = 1;
	j = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		res += ft_get_calibration(line);
		printf("line[%d]: %s", i, line);
		free(line);
		i++;
	}

	printf("\nResult: %d\n", res);
	return (0);
}