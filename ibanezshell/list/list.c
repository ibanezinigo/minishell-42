/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iibanez- <iibanez-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 09:48:28 by iibanez-          #+#    #+#             */
/*   Updated: 2022/01/05 16:15:18 by iibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list	*ft_lstnew(char *content)
{
	t_list	*rtn;

	rtn = (t_list *)malloc(sizeof(t_list));
	if (!rtn)
		return (rtn = NULL);
	rtn->next = NULL;
	rtn->token = ft_strcpy(content);
	return (rtn);
}

int	ft_lstsize(t_list *lst)
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
	if (lst)
		while (lst->next)
			lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_list *last, t_list *new)
{
	t_list	*t;

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
	int		i;

	i = 0;
	last = NULL;
	act = start;
	next = act->next;
	while (i < del)
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
		result[i] = malloc(sizeof(char) * (ft_strlen(tmp->token) + 1));
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
	char	*result;
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
