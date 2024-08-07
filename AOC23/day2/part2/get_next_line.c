#include "day2.h"

void	ft_update_lst(t_node **lst)
{
	t_node	*current;
	char	*new;

    if (*lst == NULL)
		return ;
	current = *lst;
	while (current->next != NULL)
		current = current->next;
	new = ft_get_after_nl(current->str);
	if (new == NULL)
	{
		ft_freelst(lst);
		*lst = NULL;
		return ;
	}
	ft_freelst(lst);
	ft_lstappend(lst, new);
}
int	ft_get_len(t_node *lst)
{
	t_node	*curr;
	char	*str;
	int		len;

	curr = lst;
	len = 0;
	while (curr)
	{
		str = curr->str;
		while (*str != '\n' && *str)
		{
			len++;
			str++;
		}
		if (*str == '\n')
			return (len + 1);
		curr = curr->next;
	}
	return (len);
}

int	ft_createlst(int fd, t_node **lst)
{
	char	*buff;
	int		s;
	
	buff = NULL;
	s = 0;
	while (ft_lstchr(*lst) == 0)
	{
		buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buff)
			return (-1);
		s = read(fd, buff, BUFFER_SIZE);
		if (s <= 0)
		{
			free(buff);
			return (s);
		}
		buff[s] = '\0';
		ft_lstappend(lst, buff);
	}
	return (s);
}

char	*ft_get_after_nl(char *str)
{
	char	*newlinePos;
	char	*out;
	int		len;
	int		i;

	if (!str)
        return (NULL);
	newlinePos = ft_strchr(str, '\n');
    if (!newlinePos || *(newlinePos + 1) == '\0')
        return (NULL);
    len = 0;
    while (*(newlinePos + 1 + len) != '\0')
        len++;
    out = (char *)malloc((len + 1) * sizeof(char));
    if (!out)
        return (NULL);
	i = 0;
	while (i < len)
	{
		out[i] = *(newlinePos + 1 + i);
		i++;
	}
    out[i] = '\0';
    return (out);
}

char	*ft_create_str(t_node *lst)
{
	t_node	*current;
	char	*new;
	char	*str;
	int		len;
	
	len = ft_get_len(lst);
	if (len == 0)
		return (NULL);
	new = (char *)malloc((len + 1) * sizeof(char));
	if (!new)
		return (NULL);
	current = lst;
	while (current)
	{
		str = current->str;
		while (*str != '\n' && *str)
			*new++ = *str++;
		current = current->next;
	}
	if (*str == '\n')
		*new++ = *str++;
	*new = '\0';
	return (new - len);
}

char    *get_next_line(int fd)
{
	static t_node	*lst = NULL;
	char			*line;
	int				s;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	s = ft_createlst(fd, &lst);
	if (s < 0 || !lst)
	{
		ft_freelst(&lst);
		return (NULL);
	}
	line = ft_create_str(lst);
	if (line == NULL)
	{
		ft_freelst(&lst);
		lst = NULL;
		return (NULL);
	}
	ft_update_lst(&lst);
	return (line);
}
