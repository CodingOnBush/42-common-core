#include "day1.h"

int	ft_get_first(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		// printf("loop\n");
		// printf("line[i]: %c\n", line[i]);
		if (ft_isdigit(line[i]))
			return (line[i] - '0');
		else if (ft_get_nb(&line[i]) != -1)
			return (ft_get_nb(&line[i]));
		i++;
	}
	return (-1);
}

// int main(void)
// {
// 	// txdszrn5eight3cqeight1brqr
// 	// char *line = "jvvslnkdk6qnfzjzvseight55eight";
// 	// char *line = "seightdszrn5eight3cqeight1brqr";
// 	char *line = "asdasdni5newdasdwq";
// 	printf("line: %s\n", line);
// 	printf("first: %d\n", ft_get_first(line));
// 	printf("last: %d\n", ft_get_last(line));
// 	return (0);
// }