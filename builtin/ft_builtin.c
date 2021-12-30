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

void	ft_cd(char *argv[], char **envp)
{
	int	result;
	
	if (argv[1] == NULL)
		result = chdir(getenv("HOME"));
	else if (ft_strequals(argv[1], "~"))
		result = chdir(getenv("HOME"));
	else
		result = chdir(argv[1]);
	if (result == -1)
		printf("-bash: cd: %s: %s\n", argv[1], strerror(errno));
}

void 	ft_pwd(char *argv[], char **envp)
{
	char buff[2500];

	printf("%s\n", getcwd(buff, 2500));
}

void	ft_env(char *argv[], char **envp)
{
	int	i;

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


void	ft_echo(char *argv[], char **envp)
{
	int	i;
	int	j;
	int	start;
	int	n;

	i = 1;
	start = 0;
	n = 0;
	while (argv[i] != NULL)
	{
		if (start == 1)
			printf(" ");
		if (start == 0 && argv[i][0] == '-' && ft_strlen(argv[i]) > 1)
		{
			j = 1;
			while(argv[i][j])
			{
				if (argv[i][j] != 'n')
					start = 1;
				j++;
			}
			if (start == 0 && ft_strlen(argv[i]) > 1)
				n = 1;
		}
		else
			start = 1;
		if (start == 1)
			printf("%s",argv[i]);
		i++;
	}
	if (n == 0)
		printf("\n");
}