/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iibanez- <iibanez-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 13:26:56 by iibanez-          #+#    #+#             */
/*   Updated: 2022/01/04 13:27:10 by iibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

/*DEFINIR MENSAJES DE ERROR*/
void	ft_unset(t_list *command, t_execution *exe)
{
	char	*varname;
	t_list	*tmp;

	varname = command->next->token;
	tmp = exe->envp2[0];
	while (tmp)
	{
		 if (ft_strstartwith(tmp->token, varname))
		{
			exe->envp2[0] = ft_del_node(exe->envp2[0], ft_node_position(exe->envp2[0], tmp));
			break;
		}
		tmp = tmp->next;
	}
}
