#include "day2.h"

void	ft_freelst(t_node **lst)
{
	t_node	*current;
	t_node *next;

	if (*lst == NULL)
        return;
    current = *lst;
    while (current != NULL)
	{
        next = current->next;
        free(current->str);
		free(current);
        current = next;
    }
    *lst = NULL;
}

void	ft_lstappend(t_node **lst, char *buff)
{
    t_node *newNode;
    t_node *current;

    newNode = (t_node *)malloc(sizeof(t_node));
    if (!newNode)
        return ;
    newNode->str = buff;
    newNode->next = NULL;
    if (*lst == NULL)
    {
        *lst = newNode;
        return ;
    }
    current = *lst;
    while (current->next != NULL)
        current = current->next;
    current->next = newNode;
}

int	ft_lstchr(t_node *lst)
{
    t_node *current;

	current = lst;
    while (current)
	{
        char *str = current->str;
        while (*str)
		{
            if (*str == '\n')
                return 1;
            str++;
        }
        current = current->next;
    }
    return (0);
}

char	*ft_strchr(char *s, int c)
{
	char			*ptr;
	unsigned char	val;

	if (!s)
		return (NULL);
	ptr = (char *)s;
	val = (unsigned char)c;
	while (*ptr)
	{
		if (*ptr == val)
			return (ptr);
		ptr++;
	}
	if (*ptr == val)
		return (ptr);
	return (0);
}

char	*ft_strdup(char *s, int len)
{
	char	*out;
	int		i;

	if (len < 0)
		return (NULL);
	out = malloc(sizeof(char) * (len + 1));
	if (!out)
		return (NULL);
	i = 0;
	while (i < len)
	{
		out[i] = s[i];
		i++;
	}
	out[i] = '\0';
	return (out);
}