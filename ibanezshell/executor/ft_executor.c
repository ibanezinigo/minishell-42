/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_executor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iibanez- <iibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 11:40:26 by iibanez-          #+#    #+#             */
/*   Updated: 2022/01/13 19:58:06 by iibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

char	*ft_expand(char *token, int *i, t_list *envp);
void	ft_clean_quote(t_list *command, t_list *envp);

void	ft_execve(t_execution *exe, char *path, char **args, int z)
{
	char	**env;
	//int		wr;

	env = ft_listtotable(exe->envp2[0]);
	/*if (exe->input != NULL)
	{
		printf("NO DEBE ENTRA\n");
		dup2(exe->in[0], STDIN_FILENO);
		wr = write(exe->in[1], exe->input, ft_strlen(exe->input));
	}*/
	dup2 (exe->in[0], STDIN_FILENO);
	if (z == 0)
		dup2 (exe->in[1], STDOUT_FILENO);
	close(exe->in[0]);
    //close(exe->out[1]);
	//close(exe->out[0]);
	close(exe->in[1]);
	if (path)
		execve(path, args, env);
	ft_free_list(env);
	free(path);
}

void	ft_execute_fork(t_list *command, t_execution *exe, int z)
{
	char	*path;
	char	**args;
	char	**env;

	path = NULL;
	args = ft_listtotable(command);
	ft_str_to_lower(args[0]);
	if (access(args[0], X_OK) == 0)
		path = ft_strcpy(args[0]);
	else
	{
		env = ft_split(ft_getenv(exe->envp2[0], "PATH"), ':');
		if (env != NULL)
			path = ft_search_dir(env, command->token);
		ft_free_list(env);
	}
	if (path != NULL)
		ft_execve(exe, path, args, z);
	/*
	write(exe->out[1], "bash: ", 6);
	write(exe->out[1], args[0], ft_strlen(args[0]));
	write(exe->out[1], ": command not found\n", 20);*/
	ft_free_list(args);
	exit(127);
}

void	ft_execute_not_builtin(t_list *command, t_execution *exe, int z)
{
	pid_t	pid;

//int fd;
//dup(fd, STDIN_FILENO);
//pipe(exec->in)
	pid = fork();
	if (pid == 0)
		ft_execute_fork(command, exe, z);
		//dup2(exec-in[0], fd);
	else
	{
		close(exe->out[1]);
		g_global.pid = pid;
		g_global.errnor = WEXITSTATUS(pid);
		//ft_read_execve(exe);
	}
}



void	ft_execute_aux(t_list *command, t_execution *exe, int z)
{
	ft_str_to_lower(command->token);
	ft_clean_quote(command, exe->envp2[0]);
	if (ft_strequals(command->token, "echo"))
		ft_echo(command, exe);
	else if (ft_strequals(command->token, "cd"))
		ft_cd(command, exe);
	else if (ft_strequals(command->token, "pwd"))
		ft_pwd(exe);
	else if (ft_strequals(command->token, "export"))
		ft_export(command, exe);
	else if (ft_strequals(command->token, "unset"))
		ft_unset(command, exe);
	else if (ft_strequals(command->token, "env"))
		ft_env(exe);
	else if (ft_strequals(command->token, "exit"))
		ft_exit(command);
	else
		ft_execute_not_builtin(command, exe, z);
	if (exe->input)
	{
		free(exe->input);
		exe->input = NULL;
	}
}

#include <stdio.h>
int	ft_execute(t_list **commands, t_execution *exe)
{
	int	i;

	i = 0;
	exe->output = NULL;
	exe->input = NULL;
	exe->error = NULL;
	exe->redi = 0;
	pipe(exe->in);
	while (commands[i] != NULL)
	{
		commands[i] = ft_check_input(commands[i], exe);
		commands[i] = ft_check_output(commands[i], exe);
		pipe(exe->out);
		if (!(exe->in_redi != -1 && exe->input == NULL))
		{
			if (commands[i + 1] == NULL)
				ft_execute_aux(commands[i], exe, 1);
			else
				ft_execute_aux(commands[i], exe, 0);
		}
		if (exe->redi == 1 || exe->redi == 2)
			free(exe->outputfile);
		i++;
		exe->in[1] = dup2(exe->out[0], 1);
	}
	//ft_print_output(exe);
	return (0);
}

char	*ft_expand(char *token, int *i, t_list *envp)
{
	int		j;
	char	envvar[2500];
	char	*result;
	char	init;

	result = NULL;
	j = 0;
	*i = *i + 1;
	init = token[*i];
	if (init == '?')
	{
		result = ft_itoa(g_global.errnor);
		return (result);
	}
	if (ft_isalpha(init) == 0 && init != '\0')
		return (NULL);
	while (ft_isalpha(init) && token[*i] && ft_isalnum(token[*i]) == 1)
	{
		envvar[j] = token[*i];
		j++;
		*i = *i + 1;
	}
	envvar[j] = '\0';
	if (ft_strlen(envvar) == 0)
	{
		result = ft_append_ctostr(result, '$');
		return (result);
	}
	*i = *i - 1;
	result = ft_strcpy(ft_getenv(envp, envvar));
	return (result);
}

void	ft_clean_quote(t_list *command, t_list *envp)
{
	t_list	*next;
	int		i;
	char	quote;
	char	*str;
	char	*tmp;

	next = command;
	while (next)
	{
		quote = '\0';
		i = 0;
		str = NULL;
		while (next->token[i])
		{
			if ((next->token[i] == '"' || next->token[i] == '\'') && quote == '\0')
				quote = next->token[i];
			else if (next->token[i] == quote)
				quote = '\0';
			else if (quote != '\'' && next->token[i] == '$')
			{
				tmp = ft_expand(next->token, &i, envp);
				str = ft_append_tostr(str, tmp);
			}
			else
				str = ft_append_ctostr(str, next->token[i]);
			i++;
		}
		free(next->token);
		next->token = ft_strcpy(str);
		free(str);
		next = next->next;
	}
}