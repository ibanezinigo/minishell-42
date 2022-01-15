#include "list.h"

void	ft_lstadd_back(t_list *last, t_list *new)
{
	t_list	*t;

	if (last)
	{
		t = ft_get_last_node(last);
		t->next = new;
	}
	else
		last = new;
}