/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iibanez- <iibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 09:37:54 by iibanez-          #+#    #+#             */
/*   Updated: 2022/01/14 16:31:42 by iibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

//USADO
t_list	**ft_table_to_list(char *table[], t_list	**commands)
{
	int	i;
	int	j;

	commands = malloc(sizeof(commands) * (ft_parser_count_commands(table) + 1));
	i = 0;
	j = 0;
	commands[0] = NULL;
	while (table[i])
	{
		if (commands[j] == NULL)
			commands[j] = ft_lstnew(table[i]);
		else
			ft_lstadd_back(ft_lstlast(commands[j]), ft_lstnew(table[i]));
		if (ft_strequals(table[i], "|"))
		{
			j++;
			commands[j] = NULL;
		}
		i++;
	}
	commands[j + 1] = NULL;
	return (commands);
}
