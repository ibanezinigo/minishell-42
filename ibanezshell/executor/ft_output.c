/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iibanez- <iibanez-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:52:35 by iibanez-          #+#    #+#             */
/*   Updated: 2022/01/04 18:11:49 by iibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

t_list	*ft_set_output(t_list *command, t_list *act, t_execution *exe, int redi)
{
	int		i;
	char	*path;
	char	*file;

	exe->redi = redi;
	file = ft_strcpy(act->next->token);
	i = ft_node_position(command, act);
	command = ft_del_node(command, i);
	command = ft_del_node(command, i);
	exe->outputfile = ft_strcpy(ft_getenv_value(exe->envp2[0], "PWD"));
	exe->outputfile = ft_append_tostr(exe->outputfile, "/");
	exe->outputfile = ft_append_tostr(exe->outputfile, file);
	free(file);
	if (redi == 1)
		close(open(exe->outputfile, O_RDWR | O_CREAT | O_TRUNC, 0755));
	else if (redi == 2)
		close(open(exe->outputfile, O_RDWR | O_CREAT | O_APPEND, 0755));
	return (command);
}

t_list	*ft_check_output(t_list *command, t_execution *o)
{
	t_list		*act;
	t_list		*next;

	o->redi = -1;
	act = command;
	while (act)
	{
		if (ft_strequals(act->token, ">"))
		{
			next = act->next->next;
			command = ft_set_output(command, act, o, 1);
			act = next;
		}		
		else if (ft_strequals(act->token, ">>"))
		{
			next = act->next->next;
			command = ft_set_output(command, act, o, 2);
			act = next;
		}
		else if (ft_strequals(act->token, "|") && o->redi == -1)
		{
			o->redi = 0;
			next = act->next;
			command = ft_del_node(command, ft_node_position(command, act));
			act = next;
		}
		else
			act = act->next;
	}
	return (command);
}

void	ft_redirect_output(t_execution *exe)
{
	int	fd;

	if (exe->redi == 0)
	{
		exe->input = exe->output;
		exe->output = NULL;
	}
	else if (exe->redi == 1 || exe->redi == 2)
	{
		if (exe->redi == 1)
			fd = open(exe->outputfile, O_RDWR | O_CREAT | O_TRUNC, 0755);
		else if (exe->redi == 2)
			fd = open(exe->outputfile, O_RDWR | O_CREAT | O_APPEND, 0755);
		write(fd, exe->output, ft_strlen(exe->output));
		close (fd);
		exe->input = NULL;
		exe->output = NULL;
	}
}
