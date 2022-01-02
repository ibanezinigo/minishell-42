/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iibanez- <iibanez-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 09:48:28 by iibanez-          #+#    #+#             */
/*   Updated: 2021/12/30 18:45:41 by iibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "../utils/utils.h"
#include <stdio.h>
#include <unistd.h>

t_list	*ft_lstnew(char *content)
{
	t_list *rtn;

	rtn = (t_list *)malloc(sizeof(t_list));
	if (!rtn)
		return (rtn = NULL);
	rtn->next = NULL;
	rtn->token = content;
	return (rtn);
}

int		ft_lstsize(t_list *lst)
{
	int		i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (0);
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_list *last, t_list *new)
{
	t_list *t;

	if (last)
	{
		t = ft_lstlast(last);
		t->next = new;
	}
	else
		last = new;
}

t_list	*ft_del_node(t_list *start, int del)
{
	t_list	*last;
	t_list	*act;
	t_list	*next;
	int	i;

	i = 0;
	last = NULL;
	act = start;
	next = act->next;
	while(i < del)
	{
		last = act;
		act = next;
		next = next->next;
		i++;
	}
	if (last == NULL)
	{
		free(start->token);
		free(start);
		return (next);
	}
	last->next = next;
	free(act->token);
	free(act);
	return (start);
}

int	ft_node_position(t_list *start, t_list *find)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = start;
	while (tmp != find)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	ft_print_list(t_list *start)
{
	t_list	*tmp;

	tmp = start;
	while (tmp)
	{
		if (tmp->token != NULL)
			printf("-%s-\n", tmp->token);
		tmp = tmp->next;
	}
}