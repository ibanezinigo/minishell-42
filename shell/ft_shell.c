/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shell.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iibanez- <iibanez-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 16:11:41 by iibanez-          #+#    #+#             */
/*   Updated: 2021/12/29 19:25:43 by iibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lexer/lexer.h"
#include "../executor/executor.h"
#include <stdio.h>
#include <signal.h>
#include "../utils/utils.h"

#include <readline/readline.h>
#include <readline/history.h>

void	sighandler(int a)
{
	if (a == 2)
		printf("CTRL-C");
	if (a == 3)
		return;
}

void	ft_parser(char **src)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	while (src[i] != NULL)
	{
		if (ft_strequals(src[i], "|"))
		{
			printf("\n");
			j++;
		}
		else
		{
			printf("%s ",src[i]);
		}
		i++;
	}
	printf("\n");
}



int	main(int argc, char *argv[], char**envp)
{
	char	*readl;
	char	**strlist;
	int		i;

	/*signal (SIGINT, sighandler);
	signal (SIGTERM, sighandler);
	signal (SIGQUIT, sighandler);*/
	readl = readline("test> ");
	while (1)
	{
		if (ft_strcontainstext(readl))
		{
			add_history(readl);
			strlist = ft_lexer(readl);
			ft_parser(strlist);
			//ft_execute(strlist, envp);
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
