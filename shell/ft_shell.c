/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shell.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iibanez- <iibanez-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 16:11:41 by iibanez-          #+#    #+#             */
/*   Updated: 2021/12/29 11:54:14 by iibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lexer/lexer.h"
#include "../executor/executor.h"
#include <stdio.h>

#include <readline/readline.h>
#include <readline/history.h>

int	main(int argc, char *argv[], char**envp)
{
	char	*readl;
	char	**strlist;
	int		i;

	readl = readline("test> ");
	while (1)
	{
		if (ft_strcontainstext(readl))
		{
			add_history(readl);
			strlist = ft_lexer(readl);
			ft_execute(strlist, envp);
			i = 0;
			while (strlist[i] != NULL)
			{
				i++;
			}
		}
		readl = readline("test> ");
	}
	return (0);
}
