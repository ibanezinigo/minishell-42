#include "list.h"

t_list	*ft_get_last_node(t_list *lst)
{
	if (lst)
		while (lst->next)
			lst = lst->next;
	return (lst);
}