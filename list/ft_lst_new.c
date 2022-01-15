#include "list.h"

t_list	*ft_lstnew(char *content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (node = NULL);
	node->next = NULL;
	node->token = ft_strcpy(content);
	return (node);
}