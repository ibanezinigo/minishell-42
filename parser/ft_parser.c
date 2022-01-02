#include "parser.h"

t_list **ft_table_to_list(char *table[], t_list	**commands)
{
	int	i;
	int	j;

	commands = malloc(sizeof(commands) * (ft_parser_count_commands(table) + 1));
	i = 0;
	j = 0;
	while (table[i])
	{
		if (commands[j] == NULL)
			commands[j] = ft_lstnew(table[i]);
		else
			ft_lstadd_back(ft_lstlast(commands[j]), ft_lstnew(table[i]));
		if (ft_strequals(table[i], "|"))
			j++;
		i++;
	}
	commands[j + 1] = NULL;
	return (commands);
}