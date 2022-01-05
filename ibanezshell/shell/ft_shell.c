/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shell.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iibanez- <iibanez-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 16:11:41 by iibanez-          #+#    #+#             */
/*   Updated: 2022/01/05 15:02:32 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lexer/lexer.h"
#include "../executor/executor.h"
#include "../utils/utils.h"
#include "../syntax/syntax.h"
#include <unistd.h>
#include "../list/list.h"
#include "../parser/parser.h"
#include <readline/readline.h>
#include <readline/history.h>
#include <signal.h>

int	main(int argc, char *argv[], char**envp)
{
	char		*readl;
	char		**strlist;
	t_list		**commands;
	t_execution	exe;

	argc = 0;
	argv = 0;
	exe.envp2 = ft_table_to_list(envp, exe.envp2);
	readl = readline("microshell> ");
	while (1)
	{
		if (ft_strcontainstext(readl) == 1)
		{
			add_history(readl);
			if (ft_isvalidquotes(readl) && ft_forbidden_char(readl))
			{
				strlist = ft_lexer(readl);
				commands = ft_table_to_list(strlist, commands);
				if (ft_command_checker(commands))
					ft_execute(commands, &exe);
			}	
		}
		readl = readline("microshell> ");
	}
	return (0);
}
