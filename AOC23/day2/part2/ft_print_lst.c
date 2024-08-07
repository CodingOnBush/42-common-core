#include "day2.h"

void	ft_print_lst(t_set *lst)
{
	t_set	*current;

	if (lst == NULL)
	{
		printf("List is empty\n");
		return ;
	}
	current = lst;
	printf("Printing list: ");
	while (current != NULL)
	{
		printf("[red: %d, green: %d, blue: %d] -->", current->red, current->green, current->blue);
		current = current->next;
	}
	printf("NULL\n");
}