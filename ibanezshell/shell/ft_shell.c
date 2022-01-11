/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shell.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iibanez- <iibanez-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 16:11:41 by iibanez-          #+#    #+#             */
/*   Updated: 2022/01/10 18:13:25 by iibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lexer/lexer.h"
#include "../executor/executor.h"
//#include "../utils/utils.h"
#include "../syntax/syntax.h"
//#include <unistd.h>
#include "../list/list.h"
//#include "../parser/parser.h"
#include <readline/readline.h>
#include <readline/history.h>
//#include <signal.h>



void ft_freelist(t_list **l)
{
	int		i;
	t_list	*tmp;

	i = 0;
	while (l[i])
	{
		tmp = l[i];
		while (tmp)
			tmp = ft_del_node(tmp,0);
		i++;
	}
	free(l);
}

void ft_freecharlist(char **l)
{
	int		i;

	i = 0;
	while (l[i])
	{
		free(l[i]);
		i++;
	}
	free(l);
}

int	main(int argc, char *argv[], char**envp)
{
	char		*readl;
	char		**strlist;
	t_list		**commands;
	t_execution	exe;

	argc = 0;
	argv = 0;
	exe.envp2 = ft_table_to_list(envp, exe.envp2);
	while (1)
	{
		readl = readline("microshell> ");
		if (!readl)
			break ;
		if (ft_strcontainstext(readl) == 1)
		{
			add_history(readl);
			if (ft_isvalidquotes(readl) && ft_forbidden_char(readl))
			{
				strlist = ft_lexer(readl, exe.envp2[0]);
				commands = ft_table_to_list(strlist, commands);
				if (ft_command_checker(commands))
					ft_execute(commands, &exe);
				ft_freelist(commands);
				ft_freecharlist(strlist);
			}
		}
		free(readl);
	}
	//rl_clear_history();
	ft_freelist(exe.envp2);
	//exit(0);
	return (0);
}
