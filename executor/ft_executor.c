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

#include "executor.h"

void	ft_execute_fork(t_list *command, char **envp, t_execution *e)
{
	char	*path;
	char	*args[200];
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = command;
	while (tmp)
	{
		args[i] = tmp->token;
		tmp = tmp->next;
		i++;
	}
	args[i] = NULL;
	path = ft_search_dir(ft_split(ft_getenv(envp,"PATH"), ':'), command->token);
	if (e->output != NULL)
	{
		dup2 (e->in[0], STDIN_FILENO);
		write(e->in[1], e->output, ft_strlen(e->output));
	}
	dup2 (e->out[1], STDOUT_FILENO);
	close(e->out[0]);
	close(e->out[1]);
	close(e->in[0]);
	close(e->in[1]);
	execve(path, args, envp);
	ft_die(args[0]);
}

char	*ft_execute_not_builtin(t_list *command, char **envp, t_execution *e)
{
	pid_t	pid;
	char	*buff;
	int		nbytes;

	buff = malloc(sizeof(char) * 4096);
	pipe(e->out);
	pipe(e->in);
	pid = fork();
	if (pid == 0)
		ft_execute_fork(command, envp, e);
	else
	{
		close(e->out[1]);
		close(e->in[0]);
		close(e->in[1]);
		
		nbytes = read(e->out[0], buff, 4096);
		buff[nbytes] = '\0';
		wait(NULL);
		//close(e->out[0]);
		
		return (buff);
	}
	return (NULL);
}

char	*ft_execute_aux(t_list *command, char **envp, t_execution *o)
{
	if (ft_strequals(command->token, "echo"))
		ft_echo(command);
	else if (ft_strequals(command->token, "cd"))
		ft_cd(command, envp);
	else if (ft_strequals(command->token, "pwd"))
		ft_pwd();
	else if (ft_strequals(command->token, "export"))
		printf("export\n");
	else if (ft_strequals(command->token, "unset"))
		printf("unset\n");
	else if (ft_strequals(command->token, "env"))
		ft_env(envp);
	else if (ft_strequals(command->token, "exit"))
		ft_exit();
	else
		return (ft_execute_not_builtin(command, envp, o));
	return (NULL);
}

int ft_execute(t_list **commands, char **envp)
{
	int		i;
	char	*last_output;
	char	*next_input;
	t_execution	o;
	
	i = 0;
	next_input = NULL;
	o.output = NULL;
	while (commands[i] != NULL)
	{
		commands[i] = ft_check_output(commands[i], &o);
		//ft_print_list(commands[i]);
		last_output = ft_execute_aux(commands[i] , envp, &o);
		//next_input = last_output;
		i++;
	}
	printf("OUTPUT->\n");
	if (last_output != NULL)
		printf("%s",last_output);
	return (0);
}