/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shell.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iibanez- <iibanez-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 16:11:41 by iibanez-          #+#    #+#             */
/*   Updated: 2021/12/30 18:22:59 by iibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lexer/lexer.h"
#include "../executor/executor.h"
#include <stdio.h>
#include "../utils/utils.h"
#include <unistd.h>
#include "../list/list.h"
#include "../parser/parser.h"
#include <readline/readline.h>
#include <readline/history.h>

int	main(int argc, char *argv[], char**envp)
{
	char	*readl;
	char	**strlist;
	t_list	**commands;
	
	argc = 0;
	argv = 0;
	readl = readline("test> ");
	while (1)
	{
		if (ft_strcontainstext(readl))
		{
			add_history(readl);
			strlist = ft_lexer(readl);
			commands = ft_table_to_list(strlist, commands);
			ft_execute(commands, envp);
		}
		readl = readline("test> ");
	}
	return (0);
}
