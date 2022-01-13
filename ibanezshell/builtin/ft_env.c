/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iibanez- <iibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 13:29:46 by iibanez-          #+#    #+#             */
/*   Updated: 2022/01/12 19:28:32 by iibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	ft_env(t_execution *exe)
{
	t_list	*tmp;

	tmp = exe->envp2[0];
	exe->output = malloc(1);
	exe->output[0] = '\0';
	while (tmp)
	{
		exe->output = ft_append_tostr(exe->output, tmp->token);
		exe->output = ft_append_tostr(exe->output, "\n");
		tmp = tmp->next;
	}
	g_global.errnor = 0;
}
