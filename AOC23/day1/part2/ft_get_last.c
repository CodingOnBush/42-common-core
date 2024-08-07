#include "day1.h"

int	ft_get_last(char *line)
{
	int	i;
	int	last;

	i = 0;
	last = -1;
	while (line[i])
	{
		if (ft_isdigit(line[i]))
			last = line[i] - '0';
		else if (ft_get_nb(&line[i]) != -1)
			last = ft_get_nb(&line[i]);
		i++;
	}
	return (last);
}

// int	main(void)
// {
// 	// txdszrn5eight3cqeight1brqr
// 	// char *line = "jvvslnkdk6qnfzjzvseight55eight";
// 	// char *line = "seightdszrn5eight3cqenineghtbrqr";
// 	char *line = "1thv2221";
// 	printf("line: %s\n", line);
// 	printf("last: %d\n", ft_get_last(line));
// 	return (0);
// }
