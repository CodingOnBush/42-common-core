#include "day1.h"

int	ft_strnstr(char *big, char *little, int len)
{
	int	i;

	i = 0;
	if (!big)
		return (0);
	// printf("big: %s\n", big);
	// printf("little: %s\n", little);
	while (big[i] && i < len)
	{
		if (big[i] == little[i])
			i++;
		else
			return (0);
	}
	return (1);
}

// int	main(void)
// {
// 	char	*big;
// 	char	*little;
// 	int		res;

// 	big = "ninefourone1";
// 	little = "one";
// 	res = ft_strnstr(big, little, 3);
// 	printf("Result: %d\n", res);
// 	return (0);
// }