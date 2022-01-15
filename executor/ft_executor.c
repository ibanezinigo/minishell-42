/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_executor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iibanez- <iibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 11:40:26 by iibanez-          #+#    #+#             */
/*   Updated: 2022/01/14 17:25:49 by iibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

void	ft_clean_quote(t_list *command, t_list *envp);

void	ft_execute_fork(t_list *command, t_execution *exe)
{
	char	*path;
	char	**env;
	char	**args;

	if (ft_strequals(command->token, "echo"))
		ft_echo(command, exe);
	else if (ft_strequals(command->token, "pwd"))
		ft_pwd(exe);
	else if (ft_strequals(command->token, "env"))
		ft_env(exe);
	else
	{
		args = ft_list_to_char_table(command);
		path = ft_get_path(command, exe, args);
		env = ft_list_to_char_table(exe->envp);
		if (path)
			execve(path, args, env);
		ft_free_chartable(args);
		ft_free_chartable(env);
		free(path);
		exit(127);
	}
	exit(0);
}

void	ft_execute_not_builtin(t_list *command, t_execution *exe, int i)
{
	exe->total_f = exe->total_f + 1;
	if (fork() == 0)
	{
		ft_default_pipes(exe, i);
		ft_dup_output(exe);
		ft_dup_input(exe);
		ft_close_pipes(exe->pipes, exe->total_c);
		ft_execute_fork(command, exe);
	}
}

void	ft_execute_aux(t_list *command, t_execution *exe, int i)
{
	
	ft_str_to_lower(command->token);
	ft_clean_quote(command, exe->envp);
	if (ft_strequals(command->token, "cd"))
		ft_cd(command, exe);
	else if (ft_strequals(command->token, "export"))
		ft_export(command, exe);
	else if (ft_strequals(command->token, "unset"))
		ft_unset(command, exe);
	else if (ft_strequals(command->token, "exit"))
		ft_exit(command);
	else
		ft_execute_not_builtin(command, exe, i);
}

//USADO
int	ft_execute(t_list **lcommands, t_execution *exe)
{
	int	command_n;
	int	status;

	command_n = 0;
	status = -1;
	exe->total_f = 0;
	exe->inputfile = NULL;
	ft_create_pipes(lcommands, exe);
	while (lcommands[command_n] != NULL)
	{
		lcommands[command_n] = ft_check_input(lcommands[command_n], exe);
		lcommands[command_n] = ft_output(lcommands[command_n], exe);
		if (lcommands[command_n])
			ft_execute_aux(lcommands[command_n], exe, command_n);
		if (exe->in_redi == 1 || exe->in_redi == 2)
			free(exe->inputfile);
		if (exe->redi == 1 || exe->redi == 2)
			free(exe->outputfile);
		command_n++;
	}
	ft_close_pipes(exe->pipes, exe->total_c);
	command_n = 0;
	while (command_n < exe->total_f)
	{
		wait(&status);	
		command_n++;
	}
	free(exe->pipes);
	free(exe->pids);
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