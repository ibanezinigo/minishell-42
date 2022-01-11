/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iibanez- <iibanez-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 13:31:14 by iibanez-          #+#    #+#             */
/*   Updated: 2022/01/11 11:19:14 by iibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	ft_cd(t_list *command, t_execution *exe)
{
	int		result;
	char	newpath[5000];

	if (command->next == NULL)
		result = chdir(ft_getenv(exe->envp2[0], "HOME"));
	else if (ft_strequals(command->next->token, "~"))
		result = chdir(ft_getenv(exe->envp2[0], "HOME"));
	else if (ft_strequals(command->next->token, "-"))
		result = chdir(ft_getenv(exe->envp2[0], "OLDPWD"));
	else
		result = chdir(command->next->token);
	if (result == -1)
	{
		printf("-bash: cd: %s: %s\n", command->next->token, strerror(errno));
		g_errno = 1;
	}
	else
	{
		ft_change_env(exe, "OLDPWD", ft_getenv(exe->envp2[0], "PWD"));
		getcwd(newpath, 5000);
		ft_change_env(exe, "PWD", newpath);
		g_errno = 0;
	}
}
