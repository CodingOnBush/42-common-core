#include "day1.h"

int	ft_get_calibration(char *line)
{
	int	res;

	res = ft_get_first(line);
	if (res == -1)
		return (0);
	res = (res * 10) + ft_get_last(line);
	printf("NB: %d -> ", res);
	if (res < 0)
		printf("==================NEGATIVE==================\n");
	return (res);
}

// int	main(void)
// {
// 	char	*line;
// 	int		res;

// 	line = "txdszeronineight3cqeightbrqr";
// 	res = ft_get_calibration(line);
// 	printf("Result: %d\n", res);
// 	return (0);
// }