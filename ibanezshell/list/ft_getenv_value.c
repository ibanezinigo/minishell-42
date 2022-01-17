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

/*
char	*ft_getenv_value(t_list *env, char *str)
{
	t_list	*node;
	int		i;

	node = env;
	while (node)
	{
		i = 0;
		while (node->token[i] == str[i])
			i++;
		if (str[i] == '\0' && node->token[i] == '=')
		{
			return (&node->token[i + 1]);
		}
		node = node->next;
	}
	return (NULL);
}*/
