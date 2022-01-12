/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shell.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iibanez- <iibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 16:11:41 by iibanez-          #+#    #+#             */
/*   Updated: 2022/01/12 21:46:56 by iibanez-         ###   ########.fr       */
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

void	ft_execute_line(char *readl, t_execution *exe)
{
	char		**strlist;
	t_list		**commands;

	commands = NULL;
	strlist = ft_lexer(readl, exe->envp2[0]);
	commands = ft_table_to_list(strlist, commands);
	if (ft_command_checker(commands))
		ft_execute(commands, exe);
	ft_freelist(commands);
	ft_freecharlist(strlist);
}

int	main(int argc, char *argv[], char**envp)
{
	char					*readl;
	t_execution				exe;

	argc = 0;
	argv = 0;
	g_global.pid = 0;
	exe.envp2 = ft_table_to_list(envp, exe.envp2);
	rl_catch_signals = 0;
	signal(SIGINT, sig_handler);
	signal(SIGQUIT, sig_handler);
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
	ft_freelist(exe.envp2);
	return (0);
}
