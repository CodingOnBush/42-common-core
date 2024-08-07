#include "day2.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	if (!s1 || !s2)
		return (-1);
	i = 0;
	while (!ft_isalpha(s1[i]))
		i++;
	// printf("s1[i]: %c\n", s1[i]);
	while (s1[i] && s2[i] && ft_isalpha(s1[i]))
	{
		if (s1[i] != s2[i] || !s1[i] || !s2[i])
			return (0);
		i++;
	}
	return (i);
}

// int main(void)
// {
// 	char *s1 = " 10 red, 10 blue, 10 green;";
	
// 	printf("s1: %s\n", s1);
// 	printf("res : %d\n", ft_strcmp(&s1[5], "green"));
// 	return (0);
// }