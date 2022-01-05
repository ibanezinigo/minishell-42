/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iibanez- <iibanez-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 13:31:14 by iibanez-          #+#    #+#             */
/*   Updated: 2022/01/04 13:33:27 by iibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include <string.h>
#include <stdio.h>
# include <errno.h>

//CONTROL SALIDA ERROR
void	ft_cd(t_list *command, t_execution *exe)
{
	int		result;
	char	**envp;

	envp = ft_listtotable(exe->envp2[0]);
	if (command->next == NULL)
		result = chdir(ft_getenv(envp, "HOME"));
	else if (ft_strequals(command->next->token, "~"))
		result = chdir(ft_getenv(envp, "HOME"));
	else
		result = chdir(command->next->token);
	if (result == -1)
		printf("-bash: cd: %s: %s\n", command->next->token, strerror(errno));
}