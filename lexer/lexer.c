/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iibanez- <iibanez-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 16:13:30 by iibanez-          #+#    #+#             */
/*   Updated: 2022/01/03 18:01:33 by iibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	ft_envars_extend(char *readl, char *result, int *i)
{
	int		j;
	int		size;
	char	*env;
	char	envvar[2500];

	j = 0;
	*i = *i + 1;
	while (readl[*i] && ft_isalnum(readl[*i]) == 1)
	{
		envvar[j] = readl[*i];
		j++;
		*i = *i + 1;
	}
	envvar[j] = '\0';
	if (ft_strlen(envvar) == 0)
	{
		size = ft_strlen(result);
		result[size] = '$';
		result[size + 1] = '\0';
		return;
	}
	env = getenv(envvar);
	j = 0;
	while (env && env[j])
	{
		size = ft_strlen(result);
		result[size] = env[j];
		result[size + 1] = '\0';
		j++;
	}
}

char	*ft_envars(char *readl, char *res)
{
	int		i;
	int		size;
	char	quote;
	char	result[2500];

	quote = '\0';
	result[0] = '\0';
	i = 0;
	while (readl[i] != '\0')
	{
		size = ft_strlen(result);
		if (readl[i] == '$' && quote != '\'')
		{
			ft_envars_extend(readl, result, &i);
		}
		else
		{
			result[size] = readl[i];
			result[size + 1] = '\0';
			i++;
		}
		if ((readl[i] == '\'' || readl[i] == '\"') && quote == '\0')
			quote = readl[i];
		else if (readl[i] == quote)
			quote = '\0';
	}
	res = ft_strcpy(result);
	return (res);
}

//Separa un string en tokens
char	**ft_lexer(char *readl)
{
	struct s_tokens	tokens;

	tokens.buff = ft_envars(readl, tokens.buff);
	tokens.n_tokens = ft_count_tokens(tokens.buff);
	tokens.result = malloc(sizeof(char **) * (tokens.n_tokens + 1));
	tokens.i = 0;
	while (tokens.i < tokens.n_tokens)
	{
		ft_get_next_token(&tokens);
		tokens.i = tokens.i + 1;
	}
	tokens.result[tokens.i] = NULL;
	return (tokens.result);
}
