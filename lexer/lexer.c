/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iibanez- <iibanez-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 16:13:30 by iibanez-          #+#    #+#             */
/*   Updated: 2021/12/28 19:13:19 by iibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include <stdio.h>


void	ft_envars(char *readl)
{
	int		i;
	int		j;
	int		size;
	char	result[2500];
	char	envvar[2500];

	i = 0;
	result[0] = '\0';
	envvar[0] = '\0';
	while (readl[i] != '\0')
	{
		size = ft_strlen(result);
		if (readl[i] == '$')
		{
			i++;
			j = 0;
			while (ft_isalnum(readl[i]) == 1)
			{
				envvar[j] = readl[i];
				j++;
				i++;
			}
			envvar[j] = '\0';
			//Introducir variable en el resultado
			printf("ENVAR:%s\n",getenv(envvar));
		}
		else
		{
			result[size] = readl[i];
			result[size + 1] = '\0';
		}
		i++;
	}
	printf("END:%s\n", result);
}

//Separa un string en tokens
char	**ft_lexer(char *readl)
{
	struct s_tokens tokens;

	ft_envars(readl);
	tokens.buff = readl;
	tokens.n_tokens = ft_count_tokens(readl);
	tokens.result = malloc(sizeof(char **) * tokens.n_tokens + 1);
	tokens.i = 0;
	while (tokens.i < tokens.n_tokens)
	{
		ft_get_next_token(&tokens);
		tokens.i = tokens.i + 1;
	}
	tokens.result[tokens.i] = NULL;
	return (tokens.result);
}
