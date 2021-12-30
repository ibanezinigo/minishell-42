/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_executor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iibanez- <iibanez-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 11:40:26 by iibanez-          #+#    #+#             */
/*   Updated: 2021/12/30 18:48:34 by iibanez-         ###   ########.fr       */
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
#include "../list/list.h"

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

char	*ft_execute_not_builtin(char *argv[], char **envp2, char *n_input)
{
	int		out[2];
	int		in[2];
	pid_t	pid;
	char	*buff;
	char	*path;
	int		nbytes;
	char	**envp;

	buff = malloc(sizeof(char) * 4096);
	envp = ft_split(getenv("PATH"), ':');
	path = ft_search_dir(envp, argv[0]);
	pipe(out);
	pipe(in);
	pid = fork();
	if (pid == 0)
	{
		if (n_input != NULL)
		{
			dup2 (in[0], STDIN_FILENO);
			write(in[1], n_input, ft_strlen(n_input));
		}
		dup2 (out[1], STDOUT_FILENO);
		close(out[0]);
		close(out[1]);
		close(in[0]);
		close(in[1]);
		execve(path, argv, envp2);
		ft_die(argv[0]);
	}
	else
	{
		close(out[1]);
		close(in[0]);
		close(in[1]);
		nbytes = read(out[0], buff, 4096);
		buff[nbytes] = '\0';
		wait(NULL);
		return (buff);
	}
	return (NULL);
}

char	*ft_execute_aux(char *command[], char **envp, char *n_input)
{
	if (ft_strequals(command[0], "echo"))
		ft_echo(command, envp);
	else if (ft_strequals(command[0], "cd"))
		ft_cd(command, envp);
	else if (ft_strequals(command[0], "pwd"))
		ft_pwd(command, envp);
	else if (ft_strequals(command[0], "export"))
		printf("export\n");
	else if (ft_strequals(command[0], "unset"))
		printf("unset\n");
	else if (ft_strequals(command[0], "env"))
		ft_env(command, envp);
	else if (ft_strequals(command[0], "exit"))
		ft_exit();
	else
		return(ft_execute_not_builtin(command, envp, n_input));
	return (NULL);
}

typedef struct s_output
{
	int		redi;
	int		pipe;
	int		append;
	char	*output;
}	t_output;

void	ft_check_output(char *command[], t_output *o)
{
	int			i;
	
	i = 0;
	o->redi = 0;
	o->pipe = 0;
	o->append = 0;
	while (command[i])
	{
		if (ft_strequals(command[i], ">") == 1)
		{
			o->redi = 1;
			o->append = 0;
			//crear archivo
			if (o->output)
				free(o->output);
			o->output = ft_strcpy(command[i + 1]);
			command[i][0] = '\0';
			i++;
			command[i][0]  = '\0';
		}
		if (ft_strequals(command[i], ">>") == 1)
		{
			o->redi = 1;
			o->append = 1;
			//crear archivo
			if (o->output)
				free(o->output);
			o->output = ft_strcpy(command[i + 1]);
			command[i][0]  = '\0';
			i++;
			command[i][0]  = '\0';
		}
		if (ft_strequals(command[i], "|"))
		{
			o->pipe = 1;
			command[i][0] = '\0';
		}
		i++;
	}
	/*printf("redi->%i\n", o->redi);
	printf("append->%i\n", o->append);
	printf("pipe->%i\n", o->pipe);
	printf("file->%s\n", o->output);*/
}

t_list **ft_table_to_list(char **table[], t_list	**commands)
{
	int	i;
	int	j;

	i = 1;
	while (table[i] != NULL)
		i++;
	commands = malloc(sizeof(commands) * i);
	i = 0;
	while (table[i])
	{
		j = 0;
		while (table[i][j])
		{
			if (j == 0)
				commands[i] = ft_lstnew(table[i][j]);
			else if (table[i][j] != NULL)
				ft_lstadd_back(commands[i], ft_lstnew(table[i][j]));
			j++;
		}
		i++;
	}
	commands[i] = NULL;
	return (commands);
}

int ft_execute(char **table[], char **envp)
{
	int		i;
	char	*last_output;
	char	*next_input;
	t_list	**commands;
	t_output	o;
	
	i = 0;
	next_input = NULL;
	commands = ft_table_to_list(table, commands);
	while (table[i] != NULL)
	{
		//ft_check_output(table[i], &o);

		last_output = ft_execute_aux(table[i] , envp, NULL);
		next_input = last_output;
		i++;
	}
	if (last_output != NULL)
		printf("%s",last_output);
	return (0);
}