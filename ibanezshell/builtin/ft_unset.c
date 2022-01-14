/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iibanez- <iibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 13:26:56 by iibanez-          #+#    #+#             */
/*   Updated: 2022/01/12 19:28:34 by iibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	ft_unset_error(t_execution *exe, char *err)
{
	exe->error = ft_append_tostr(exe->error, "bash: export: `");
	exe->error = ft_append_tostr(exe->error, err);
	exe->error = ft_append_tostr(exe->error, "': not a valid identifier\n");
	g_global.errnor = 1;
}

/*DEFINIR MENSAJES DE ERROR*/
void	ft_unset(t_list *command, t_execution *exe)
{
	char	*varname;
	t_list	*tmp;

	g_global.errnor = 0;
	if (command->next == NULL || command->next->token == NULL)
		return ;
	if ((ft_isdigit(command->next->token[0]) == 1)
		|| (ft_strisalnum(command->next->token) == 0))
	{
		ft_unset_error(exe, command->next->token);
		return ;
	}
	varname = command->next->token;
	tmp = exe->envp2[0];
	while (tmp)
	{
		if (ft_strstartwith(tmp->token, varname))
		{
			exe->envp2[0] = ft_del_node(exe->envp2[0],
					ft_node_position(exe->envp2[0], tmp));
			break ;
		}
		tmp = tmp->next;
	}
}