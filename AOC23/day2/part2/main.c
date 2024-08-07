#include "day2.h"

int	main(void)
{
	int		fd;
	char	*line;
	int		res;
	t_set	*lst;

	fd = open("input", O_RDONLY);
	if (fd < 0)
		return (0);
	res = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		res += ft_get_power(ft_create_set_list(line));
		free(line);
	}
	printf("Result: %d\n", res);
	return (0);
}