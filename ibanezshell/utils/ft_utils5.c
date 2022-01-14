/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iibanez- <iibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 13:13:26 by iibanez-          #+#    #+#             */
/*   Updated: 2022/01/14 16:34:11 by iibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

//USADO
void	ft_freelist2d(t_list **l)
{
	int		i;
	t_list	*tmp;

	i = 0;
	while (l[i])
	{
		tmp = l[i];
		while (tmp)
			tmp = ft_del_node(tmp, 0);
		i++;
	}
	free(l);
}

void	ft_freelist1d(t_list *l)
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

void	ft_freecharlist(char **l)
{
	int		i;

	i = 0;
	while (l[i])
	{
		free(l[i]);
		i++;
	}
	free(l);
}

char    *ft_append_ctostr(char *str, char c)
{
	char	*tmp;
	int		i;

	if (str == NULL)
	{
		str = malloc(2);
		str[0] = c;
		str[1] = '\0';
		return (str);
	}
	tmp = malloc(ft_strlen(str) + 2);
	i = 0;
	while (str[i])
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = c;
	tmp[i + 1] = '\0';
	free(str);
	return (tmp);
}
