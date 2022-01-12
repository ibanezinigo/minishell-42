/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iibanez- <iibanez-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:59:20 by iibanez-          #+#    #+#             */
/*   Updated: 2022/01/11 18:00:00 by iibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int	ft_node_position(t_list *start, t_list *find)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = start;
	while (tmp && tmp != find)
	{
		tmp = tmp->next;
		i++;
	}
	if (tmp == find)
		return (i);
	else
		return (-1);
}

char	**ft_listtotable(t_list *lst)
{
	char	**result;
	t_list	*tmp;
	int		i;

	result = malloc(sizeof(char *) * (ft_lstsize(lst) + 1));
	tmp = lst;
	i = 0;
	while (tmp)
	{
		result[i] = ft_strcpy(tmp->token);
		tmp = tmp->next;
		i++;
	}
	result[i] = NULL;
	return (result);
}

char	*ft_getenv_value(t_list *env, char *str)
{
	t_list	*tmp;
	int		i;

	tmp = env;
	while (tmp)
	{
		i = 0;
		while (tmp->token[i] == str[i])
			i++;
		if (str[i] == '\0' && tmp->token[i] == '=')
		{
			return (&tmp->token[i + 1]);
		}
		tmp = tmp->next;
	}
	return (NULL);
}
