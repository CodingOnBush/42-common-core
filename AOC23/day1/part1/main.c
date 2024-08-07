#include "day1.h"

int	main(void)
{
	int		fd;
	char	*line;
	int		res;

	fd = open("input", O_RDONLY);
	if (fd == -1)
		return (0);
	res = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		res += ft_get_calibration(line);
		free(line);
	}
	printf("Result: %d\n", res);
	return (0);
}