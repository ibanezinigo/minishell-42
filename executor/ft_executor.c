/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_executor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iibanez- <iibanez-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 11:40:26 by iibanez-          #+#    #+#             */
/*   Updated: 2022/01/11 17:58:05 by iibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

void	ft_execve(t_execution *exe, char *path, char **args)
{
	char	**env;
	int		wr;

	env = ft_listtotable(exe->envp2[0]);
	if (exe->input != NULL)
	{
		dup2(exe->in[0], STDIN_FILENO);
		wr = write(exe->in[1], exe->input, ft_strlen(exe->input));
	}
	dup2 (exe->out[1], STDOUT_FILENO);
	close(exe->out[0]);
	close(exe->out[1]);
	close(exe->in[0]);
	close(exe->in[1]);
	if (path)
		execve(path, args, env);
	ft_free_list(env);
	free(path);
}

void	ft_execute_fork(t_list *command, t_execution *exe)
{
	char	*path;
	char	**args;
	char	**env;

	g_errno = 0;
	args = ft_listtotable(command);
	if (access(args[0], X_OK) == 0)
		path = ft_strcpy(args[0]);
	else
	{
		env = ft_split(ft_getenv(exe->envp2[0], "PATH"), ':');
		path = ft_search_dir(env, command->token);
		ft_free_list(env);
	}
	if (path != NULL)
		ft_execve(exe, path, args);
	write(exe->out[1], "bash: ", 6);
	write(exe->out[1], args[0], ft_strlen(args[0]));
	write(exe->out[1], ": command not found\n", 20);
	ft_free_list(args);
	exit(127);
}

void	ft_execute_not_builtin(t_list *command, t_execution *exe)
{
	pid_t	pid;

	pipe(exe->out);
	pipe(exe->in);
	pid = fork();
	if (pid == 0)
		ft_execute_fork(command, exe);
	else
	{
		close(exe->out[1]);
		close(exe->in[0]);
		close(exe->in[1]);
		wait(&pid);
		g_errno = WEXITSTATUS(pid);
		ft_read_execve(exe);
		close(exe->out[0]);
	}
}

void	ft_execute_aux(t_list *command, t_execution *exe)
{
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
		ft_execute_not_builtin(command, exe);
	if (exe->input)
	{
		free(exe->input);
		exe->input = NULL;
	}
}

int	ft_execute(t_list **commands, t_execution *exe)
{
	int			i;

	i = 0;
	exe->output = NULL;
	exe->input = NULL;
	exe->error = NULL;
	exe->redi = 0;
	while (commands[i] != NULL)
	{
		commands[i] = ft_check_input(commands[i], exe);
		commands[i] = ft_check_output(commands[i], exe);
		if (!(exe->in_redi != -1 && exe->input == NULL))
		{
			ft_execute_aux(commands[i], exe);
			ft_redirect_output(exe);
		}
		if (exe->redi == 1 || exe->redi == 2)
			free(exe->outputfile);
		i++;
	}
	ft_print_output(exe);
	return (0);
}
