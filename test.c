/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iibanez- <iibanez-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 20:10:29 by iibanez-          #+#    #+#             */
/*   Updated: 2021/12/22 13:24:05 by iibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include <readline/readline.h>
#include <readline/history.h>

//Separa un string en tokens
char	**ft_lexer(char *readl)
{
	char	*buff;
	char	**result;
	int		i;

	buff = ft_strcpy(readl);
	while (buff != NULL)
	{
		i = 0;
	}
	free(buff);
	return (NULL);
}

int	main(void)
{
	char	*readl;

	readl = readline("test> ");
	while (readl[0] != 'e')
	{
		add_history(readl);
		printf("%s\n", readl);
		printf("%i\n", ft_count_tokens(readl));
		readl = readline("test> ");
	}
	return (0);
}
