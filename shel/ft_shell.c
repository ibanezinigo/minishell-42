/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shell.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iibanez- <iibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 16:11:41 by iibanez-          #+#    #+#             */
/*   Updated: 2022/01/14 17:01:32 by iibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "executor.h"
#include "syntax.h"
#include "list.h"
#include <readline/readline.h>
#include <readline/history.h>
#include <signal.h>
#include <termios.h>

void	sig_handler(int signum)
{
	if (signum == 2 && g_global.pid == 0)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	if (signum == 2 && g_global.pid != 0)
		printf("\n");
	if (signum == 3 && g_global.pid != 0)
	{
		printf("Quit: 3\n");
	}
}

//USADO
t_list	**ft_parse_2(t_list *list)
{
	int		i;
	int		j;
	t_list	*l;
	t_list	*tmp;
	t_list	**result;
	
	i = 1;
	l = list;
	while (l)
	{
		if (ft_strequals(l->token, "|"))
			i++;
		l = l->next;
	}
	result = malloc(sizeof(t_list *) * (i + 1));
	i = 0;
	l = list;
	j = 0;
	while (l)
	{
		if (j == 0)
			result[i] = l;
		j++;
		if (ft_strequals(l->token, "|"))
		{
			tmp = l->next;
			l->next = NULL;
			l = tmp;
			i++;
			j = 0;
		}
		else
			l = l->next;
	}
	result[i + 1] = NULL;
	return (result);
}

//USADO
void	ft_execute_line(char *readl, t_execution *exe)
{
	t_list		**commands;
	t_list		*list;

	commands = NULL;
	list = ft_lexer_2(readl);
	commands = ft_parse_2(list);
	if (ft_command_checker(commands))
		ft_execute(commands, exe);
	ft_freelist2d(commands);
}

int	main(int argc, char *argv[], char**envp)
{
	char					*readl;
	t_execution				exe;

	argc = 0;
	argv = 0;
	g_global.pid = 0;
	exe.envp2 = ft_table_to_list(envp, exe.envp2);
	exe.defaultout = dup(1);
	//rl_catch_signals = 0;
	//signal(SIGINT, sig_handler);
	//signal(SIGQUIT, sig_handler);
	while (1)
	{
		readl = readline("microshell> ");
		if (!readl)
			break ;
		if (ft_strcontainstext(readl) == 1)
		{
			add_history(readl);
			if (ft_isvalidquotes(readl) && ft_forbidden_char(readl))
				ft_execute_line(readl, &exe);
		}
		free(readl);
	}
	ft_freelist2d(exe.envp2);
	return (0);
}
