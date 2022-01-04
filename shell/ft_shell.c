/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shell.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iibanez- <iibanez-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 16:11:41 by iibanez-          #+#    #+#             */
/*   Updated: 2022/01/04 14:15:28 by iibanez-         ###   ########.fr       */
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

int	main(int argc, char *argv[], char**envp)
{
	char		*readl;
	char		**strlist;
	t_list		**commands;
	t_execution	exe;

	argc = 0;
	argv = 0;
	exe.envp2 = ft_table_to_list(envp, exe.envp2);
	readl = argv[2];
	if (ft_strcontainstext(readl))
	{
		if (ft_isvalidquotes(readl))
		{
			strlist = ft_lexer(readl);
			commands = ft_table_to_list(strlist, commands);
			ft_execute(commands, &exe);
		}
		else
			printf("-bash: quotes not closed.\n");		
	return (0);
}


/*
int	main(int argc, char *argv[], char**envp)
{
	char		*readl;
	char		**strlist;
	t_list		**commands;
	t_execution	exe;

	argc = 0;
	argv = 0;
	exe.envp2 = ft_table_to_list(envp, exe.envp2);
	readl = readline("test> ");
	while (1)
	{
		if (ft_strcontainstext(readl))
		{
			add_history(readl);
			if (ft_isvalidquotes(readl))
			{
				strlist = ft_lexer(readl);
				commands = ft_table_to_list(strlist, commands);
				ft_execute(commands, &exe);
			}
			else
				printf("-bash: quotes not closed.\n");		
		}
		readl = readline("test> ");
	}
	return (0);
}*/
