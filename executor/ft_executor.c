/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_executor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iibanez- <iibanez-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 11:40:26 by iibanez-          #+#    #+#             */
/*   Updated: 2022/01/03 19:46:04 by iibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

void	ft_execute_fork(t_list *command, t_execution *exe)
{
	char	*path;
	char	**args;
	char	**env;

	args = ft_listtotable(command);
	env = ft_listtotable(exe->envp2[0]);
	if (access(args[0], X_OK) == 0)
		path = args[0];
	else
		path = ft_search_dir(ft_split(ft_getenv(env, "PATH"), ':'), command->token);
	if (exe->input != NULL)
	{
		dup2 (exe->in[0], STDIN_FILENO);
		write(exe->in[1], exe->input, ft_strlen(exe->input));
	}
	dup2 (exe->out[1], STDOUT_FILENO);
	close(exe->out[0]);
	close(exe->out[1]);
	close(exe->in[0]);
	close(exe->in[1]);
	execve(path, args, env);
	ft_die(args[0]);
}

void	ft_execute_not_builtin(t_list *command, t_execution *exe)
{
	pid_t	pid;
	char	*buff;
	int		nbytes;

	buff = malloc(sizeof(char) * 4096);
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
		wait(NULL);
		nbytes = read(exe->out[0], buff, 4096);
		buff[nbytes] = '\0';
		close(exe->out[0]);
		exe->output = buff;
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
		printf("export\n");
	else if (ft_strequals(command->token, "unset"))
		printf("unset\n");
	else if (ft_strequals(command->token, "env"))
		ft_env(exe);
	else if (ft_strequals(command->token, "exit"))
		ft_exit();
	else
		ft_execute_not_builtin(command, exe);
}

int	ft_execute(t_list **commands, t_execution *exe)
{
	int			i;
	char		*next_input;

	i = 0;
	exe->output = NULL;
	exe->input = NULL;
	exe->error = NULL;
	while (commands[i] != NULL)
	{
		commands[i] = ft_check_output(commands[i], exe);
		commands[i] = ft_check_input(commands[i], exe);
		if (!(exe->in_redi != -1 && exe->input == NULL))
		{
			ft_execute_aux(commands[i], exe);
			ft_redirect_output(exe);
		}
		i++;
	}
	if (exe->redi == -1 && exe->output)
	{
		printf("%s", exe->output);
	}
	if (exe->error)
	{
		printf("%s", exe->error);
	}
	return (0);
}
