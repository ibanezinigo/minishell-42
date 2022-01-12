/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iibanez- <iibanez-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 13:18:46 by iibanez-          #+#    #+#             */
/*   Updated: 2022/01/11 17:28:30 by iibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	ft_change_env(t_execution *exe, char *search, char *new)
{
	t_list	*tmp;
	char	*newvar;

	tmp = exe->envp2[0];
	while (tmp)
	{
		if (ft_strstartwith(tmp->token, search))
		{
			free(tmp->token);
			tmp->token = ft_strcpy(search);
			tmp->token = ft_append_tostr(tmp->token, "=");
			tmp->token = ft_append_tostr(tmp->token, new);
			return ;
		}
		tmp = tmp->next;
	}
	newvar = ft_strcpy(search);
	newvar = ft_append_tostr(newvar, "=");
	newvar = ft_append_tostr(newvar, new);
	tmp = ft_lstnew(newvar);
	free(newvar);
	ft_lstadd_back(exe->envp2[0], tmp);
}

void	ft_export_error(t_execution *exe, char *err)
{
	exe->error = ft_append_tostr(exe->error, "bash: export: `");
	exe->error = ft_append_tostr(exe->error, err);
	exe->error = ft_append_tostr(exe->error, "': not a valid identifier\n");
	g_errno = 1;
}

/*DEFINIR MENSAJES DE ERROR*/
void	ft_export(t_list *command, t_execution *exe)
{
	char	**var;

	g_errno = 0;
	if (command->next == NULL || command->next->token == NULL)
		return ;
	var = ft_split(command->next->token, '=');
	if (ft_isdigit(var[0][0]) == 1)
		ft_export_error(exe, var[0]);
	else if (ft_strisalnum(var[0]) == 0)
		ft_export_error(exe, var[0]);
	else if (var[1])
		ft_change_env(exe, var[0], var[1]);
	ft_free_list(var);
	return ;
}
