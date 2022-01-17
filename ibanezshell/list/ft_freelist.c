#include "list.h"

void	ft_freelist(t_list *l)
{
	t_list	*act;
	t_list	*next;

	act = l;
	while (act)
	{
		next = act->next;
		ft_del_node(act, 0);
		act = next;
	}
}