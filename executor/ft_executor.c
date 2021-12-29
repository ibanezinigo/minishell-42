/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_executor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iibanez- <iibanez-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 11:40:26 by iibanez-          #+#    #+#             */
/*   Updated: 2021/12/29 15:03:39 by iibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>
#include "../utils/utils.h"

void	ft_die(char *e)
{
	fprintf(stderr, "bash: %s: command not found\n", e);
	exit(EXIT_FAILURE);
}

char	*ft_search_dir(char **path, char *search)
{
	int				i;
	DIR				*dp;
	struct dirent	*dirp;
	char			*tmp;
	char			*result;

	i = 0;
	while (path[i])
	{
		dp = opendir(path[i]);
		dirp = readdir(dp);
		while (dirp != NULL)
		{
			if (ft_strequals(search, dirp->d_name))
			{
				tmp = ft_strcat(path[i], "/");
				result = ft_strcat(tmp, dirp->d_name);
				free(tmp);
				closedir(dp);
				return (result);
			}
			dirp = readdir(dp);
		}
		i++;
	}
	closedir(dp);
	return (NULL);
}

int	ft_execute_not_builtin(char *argv[], char **envp2)
{
	int		link[2];
	pid_t	pid;
	char	foo[4096];
	char	*path;
	int		nbytes;
	char	**envp;

	envp = ft_split(getenv("PATH"), ':');
	path = ft_search_dir(envp, argv[0]);
	if (pipe(link) == -1)
		ft_die("pipe");
	pid = fork();
	if (pid == -1)
		ft_die("fork");
	if (pid == 0)
	{
		dup2 (link[1], STDOUT_FILENO);
		close(link[0]);
		close(link[1]);
		execve(path, argv, envp2);
		ft_die(argv[0]);
	}
	else
	{
		close(link[1]);
		nbytes = read(link[0], foo, sizeof(foo));
		printf("%.*s", nbytes, foo);
		wait(NULL);
	}
	return (0);
}

void	ft_cd(char *argv[], char **envp)
{
	int	result;
	
	if (argv[1] == NULL)
		return ;
	if (ft_strequals(argv[1], "~"))
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

int ft_execute(char *argv[], char **envp)
{
	if (ft_strequals(argv[0], "echo"))
		ft_echo(argv, envp);
	else if (ft_strequals(argv[0], "cd"))
		ft_cd(argv, envp);
	else if (ft_strequals(argv[0], "pwd"))
		ft_pwd(argv, envp);
	else if (ft_strequals(argv[0], "export"))
		printf("export\n");
	else if (ft_strequals(argv[0], "unset"))
		printf("unset\n");
	else if (ft_strequals(argv[0], "env"))
		ft_env(argv, envp);
	else if (ft_strequals(argv[0], "exit"))
		ft_exit();
	else
		ft_execute_not_builtin(argv, envp);
	return (0);
}