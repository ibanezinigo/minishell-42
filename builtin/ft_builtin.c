/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iibanez- <iibanez-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 11:25:53 by iibanez-          #+#    #+#             */
/*   Updated: 2021/12/30 11:27:46 by iibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>
#include "../utils/utils.h"
#include "../builtin/builtin.h"


void	ft_cd(t_list *command, char **envp)
{
	int	result;
	
	if (command->next == NULL)
		result = chdir(ft_getenv(envp, "HOME"));
	else if (ft_strequals(command->next->token, "~"))
		result = chdir(ft_getenv(envp, "HOME"));
	else
		result = chdir(command->next->token);
	if (result == -1)
		printf("-bash: cd: %s: %s\n", command->next->token, strerror(errno));
}

void 	ft_pwd()
{
	char buff[2500];

	printf("%s\n", getcwd(buff, 2500));
}

void	ft_env(char **envp)
{
	int	i;

	i = 0;
	while(envp[i])
	{
		printf("%s\n", envp[i]);
		i++;
	}
}

void	ft_exit()
{
	exit(EXIT_SUCCESS);
}

void	ft_echo(t_list *command)
{
	int	j;
	int	start;
	int	n;
	t_list	*tmp;

	start = 0;
	n = 0;
	tmp = command->next;
	while (tmp != NULL)
	{
		if (start == 1)
			printf(" ");
		if (start == 0 && tmp->token[0] == '-' && ft_strlen(tmp->token) > 1)
		{
			j = 1;
			while(tmp->token[j])
			{
				if (tmp->token[j] != 'n')
					start = 1;
				j++;
			}
			if (start == 0 && ft_strlen(tmp->token) > 1)
				n = 1;
		}
		else
			start = 1;
		if (start == 1)
			printf("%s", tmp->token);
		tmp = tmp->next;
	}
	if (n == 0)
		printf("\n");
}