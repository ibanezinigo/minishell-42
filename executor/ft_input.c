/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iibanez- <iibanez-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 14:24:59 by iibanez-          #+#    #+#             */
/*   Updated: 2022/01/11 17:30:14 by iibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

char	*ft_read_file(char	*path)
{
	int		fd;
	int		size;
	char	buff[1000];
	char	*result;

	fd = open(path, O_RDONLY);
	size = read(fd, buff, 999);
	if (size == -1)
		return (NULL);
	buff[size] = '\0';
	result = malloc(1);
	result[0] = 0;
	while (size > 0)
	{
		result = ft_append_tostr(result, buff);
		size = read(fd, buff, 999);
		buff[size] = '\0';
	}
	close(fd);
	return (result);
}

t_list	*ft_doc_here(t_list *command, t_list *act, t_execution *exe, int redi)
{
	int		i;
	char	*end;
	char	*input;
	char	*result;

	if (exe->in_redi == 1 || exe->in_redi == 2)
		free(exe->input);
	exe->in_redi = redi;
	end = ft_strcpy(act->next->token);
	i = ft_node_position(command, act);
	command = ft_del_node(command, i);
	command = ft_del_node(command, i);
	input = readline("> ");
	result = malloc(1);
	result[0] = '\0';
	while (ft_strequals(end, input) == 0)
	{
		result = ft_append_tostr(result, input);
		result = ft_append_tostr(result, "\n");
		free(input);
		input = readline("> ");
	}
	free(input);
	exe->input = result;
	free(end);
	return (command);
}

t_list	*ft_set_input(t_list *command, t_list *act, t_execution *exe, int redi)
{
	int		i;
	char	*path;
	char	*file;

	if (exe->in_redi == 1 || exe->in_redi == 2)
		free(exe->input);
	exe->in_redi = redi;
	file = ft_strcpy(act->next->token);
	i = ft_node_position(command, act);
	command = ft_del_node(command, i);
	command = ft_del_node(command, i);
	path = ft_strcpy(ft_getenv_value(exe->envp2[0], "PWD"));
	path = ft_append_tostr(path, "/");
	path = ft_append_tostr(path, file);
	exe->input = ft_read_file(path);
	if (exe->input == NULL)
	{
		exe->error = ft_append_tostr(exe->error, "-bash: ");
		exe->error = ft_append_tostr(exe->error, file);
		exe->error = ft_append_tostr(exe->error, ": No such file or directory\n");
		g_errno = 1;
	}
	free(file);
	free(path);
	return (command);
}

t_list	*ft_check_input(t_list *command, t_execution *exe)
{
	t_list		*act;
	t_list		*next;

	if (exe->redi != 0 && exe->input)
	{
		free(exe->input);
		exe->input = NULL;
	}
	exe->in_redi = -1;
	act = command;
	while (act)
	{
		if (ft_strequals(act->token, "<"))
		{
			next = act->next->next;
			command = ft_set_input(command, act, exe, 1);
			act = next;
			if (exe->input == NULL)
				break ;
		}		
		else if (ft_strequals(act->token, "<<"))
		{
			next = act->next->next;
			command = ft_doc_here(command, act, exe, 2);
			act = next;
		}
		else
			act = act->next;
	}
	return (command);
}
