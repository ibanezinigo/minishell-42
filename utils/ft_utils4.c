/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iibanez- <iibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 18:31:53 by iibanez-          #+#    #+#             */
/*   Updated: 2022/01/14 16:31:54 by iibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	return (0);
}

int	ft_strisalnum(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isalnum(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

//USADO
int	ft_parser_count_commands(char **src)
{
	int	i;
	int	result;

	result = 1;
	i = 0;
	while (src[i])
	{
		if (ft_strequals(src[i], "|"))
			result++;
		i++;
	}
	return (result);
}

char	*ft_getenv(t_list *l, char *path)
{
	int		j;
	char	*value;
	t_list	*next;

	next = l;
	while (next)
	{
		value = next->token;
		j = 0;
		while (path[j])
		{
			if (value[j] != path[j])
				break ;
			j++;
		}
		if (value[j] == '=' && path[j] == '\0')
			return (&value[j + 1]);
		next = next->next;
	}
	return (NULL);
}
