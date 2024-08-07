#include "day2.h"

void	ft_add_set(t_set **lst, t_set *newset)
{
	t_set	*current;

	current = *lst;
	printf("yo\n");
	if (*lst == NULL)
	{
		*lst = newset;
		return ;
	}
	while (current->next != NULL)
		current = current->next;
	current->next = newset;
}
