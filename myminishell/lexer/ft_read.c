/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 12:20:06 by ingonzal          #+#    #+#             */
/*   Updated: 2022/01/04 12:23:22 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

char **ft_lexer(char *promt);

int	main()
{
	char *prompt;
	char **res;
	int	i;

	i = 0;
	while (1)
	{
		prompt = readline("Minishell>");
		add_history(prompt);
		 res = ft_lexer(prompt);	
		while (res[i])
		{
			printf("%s\n", res[i]);
			i++;
		}
		i = 0;
	}
	return (0);
}
