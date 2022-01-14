/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iibanez- <iibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 13:28:48 by iibanez-          #+#    #+#             */
/*   Updated: 2022/01/14 17:14:32 by iibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	ft_echo_arguments(int *start, t_list *tmp, int *n)
{
	int	j;

	if (*start == 0 && tmp->token[0] == '-' && ft_strlen(tmp->token) > 1)
	{
		j = 1;
		while (tmp->token[j])
		{
			if (tmp->token[j] != 'n')
				*start = 1;
			j++;
		}
		if (*start == 0 && ft_strlen(tmp->token) > 1)
			*n = 1;
	}
	else
		*start = 1;
}

void	ft_echo(t_list *command, t_execution *exe)
{
	int		start;
	int		n;
	t_list	*tmp;

	start = 0;
	n = 0;
	tmp = command->next;
	
	while (tmp != NULL)
	{
		if (start == 1)
			//exe->output = ft_append_tostr(exe->output, " ");
			write(1, " ", 1);
		ft_echo_arguments(&start, tmp, &n);
		if (start == 1)
			//exe->output = ft_append_tostr(exe->output, tmp->token);
			//printf("%s", tmp->token);
			write(1, tmp->token, ft_strlen(tmp->token));
		tmp = tmp->next;
	}
	if (n == 0)
		//exe->output = ft_append_tostr(exe->output, "\n");
		//printf("\n");
		write(1, "\n", 1);
	g_global.errnor = 0;
}
