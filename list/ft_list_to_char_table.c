#include "list.h"

char	**ft_list_to_char_table(t_list *lst)
{
	char	**result;
	t_list	*node;
	int		i;

	result = malloc(sizeof(char *) * (ft_lstsize(lst) + 1));
	node = lst;
	i = 0;
	while (node)
	{
		result[i] = ft_strcpy(node->token);
		node = node->next;
		i++;
	}
	result[i] = NULL;
	return (result);
}