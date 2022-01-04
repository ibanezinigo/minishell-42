/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iibanez- <iibanez-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 13:18:46 by iibanez-          #+#    #+#             */
/*   Updated: 2022/01/04 13:25:32 by iibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

/*DEFINIR MENSAJES DE ERROR*/
void	ft_export(t_list *command, t_execution *exe)
{
	char	**var;
	t_list	*tmp;

	if (!command->next)
	{
		//IMPRIMIR export completo
		return ;
	}
	var = ft_split(command->next->token, '=');
	if (var[1])
	{
		tmp = exe->envp2[0];
		while (tmp)
		{
			 if (ft_strstartwith(tmp->token, var[0]))
			{
				free(tmp->token);
				tmp->token = ft_strcpy(var[0]);
				tmp->token = ft_append_tostr(tmp->token, "=");
				tmp->token = ft_append_tostr(tmp->token, var[1]);
				ft_free_list(var);
				return ;
			}
			tmp = tmp->next;
		}
	}
	ft_free_list(var);
	return ;
}