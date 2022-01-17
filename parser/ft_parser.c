/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iibanez- <iibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 09:37:54 by iibanez-          #+#    #+#             */
/*   Updated: 2022/01/17 11:58:33 by iibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

#include <stdio.h>
t_list	**ft_parse(t_list *list)
{
	int		i;
	int		j;
	t_list	*l;
	t_list	*tmp;
	t_list	**result;
	
	i = 1;
	l = list;
	while (l)
	{
		if (ft_strequals(l->token, "|"))
			i++;
		l = l->next;
	}
	result = malloc(sizeof(t_list *) * (i + 1));
	i = 0;
	l = list;
	j = 0;
	while (l)
	{
		if (j == 0)
			result[i] = l;
		j++;
		if (ft_strequals(l->token, "|"))
		{
			tmp = l->next;
			l->next = NULL;
			l = tmp;
			i++;
			j = 0;
		}
		else
			l = l->next;
	}
	if (j == 0)
		result[i] = NULL;
	result[i + 1] = NULL;
	return (result);
}
