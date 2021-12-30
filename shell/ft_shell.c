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

#include <readline/readline.h>
#include <readline/history.h>


int	ft_parser_count_commands(char **src)
{
	int	i;
	int	result;

	result = 1;
	i = 0;
	while (src[i])
	{
		if (ft_strequals(src[i], "|"))
			result++;
		i++;
	}
	return (result);
}

char	***ft_parser(char **src)
{
	int		lines;
	char	***table;
	int		i;
	int		j;
	int		k;

	lines = ft_parser_count_commands(src);
	table = malloc(sizeof(char ***) * (lines + 1));
	i = 0;
	k = 0;
	while (i < lines)
	{
		table[i] = malloc(sizeof (char **) * 50);
		j = 0;
		while (src[k] != NULL)
		{
			table[i][j] = src[k];
			j++;
			if (ft_strequals(src[k], "|") == 1)
				break ;
			k++;
		}
		table[i][j] = NULL;
		k++;
		i++;
	}
	table[i] = NULL;
	return (table);
}

int	main(int argc, char *argv[], char**envp)
{
	char	*readl;
	char	**strlist;
	char	***table;

	readl = readline("test> ");
	while (1)
	{
		if (ft_strcontainstext(readl))
		{
			add_history(readl);
			strlist = ft_lexer(readl);
			table = ft_parser(strlist);
			ft_execute(table, envp);
		}
		readl = readline("test> ");
	}
	return (0);
}
