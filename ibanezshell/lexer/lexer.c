/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iibanez- <iibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 16:13:30 by iibanez-          #+#    #+#             */
/*   Updated: 2022/01/14 16:34:33 by iibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	ft_envar_extend_aux(char *envvar, t_list *envp, char *result)
{
	char	*env;
	int		j;
	int		size;

	if (ft_strequals(envvar, "?"))
		env = ft_itoa(g_global.errnor);
	else
		env = ft_strcpy(ft_getenv(envp, envvar));
	j = 0;
	while (env && env[j])
	{
		size = ft_strlen(result);
		result[size] = env[j];
		result[size + 1] = '\0';
		j++;
	}
	free(env);
}

void	ft_envars_extend(char *readl, char *result, int *i, t_list *envp)
{
	int		j;
	int		size;
	char	envvar[2500];

	j = 0;
	*i = *i + 1;
	while (readl[*i] && (ft_isalnum(readl[*i]) == 1 || readl[*i] == '?'))
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
		return ;
	}
	ft_envar_extend_aux(envvar, envp, result);
}

char	*ft_envars(char *readl, t_list *envp)
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
			ft_envars_extend(readl, result, &i, envp);
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
	return (ft_strcpy(result));
}

//USADO
t_list	*ft_lexer_2(char *readl)
{
	char 	*str;
	int		i;
	char	quote;
	char	*token;
	t_list	*start;
	t_list	*l;

	start = NULL;
	str = ft_strcpy(readl);
	while(ft_strcontainstext(str))
	{
		i = 0;
		while (ft_isspace(str[i]))
			i++;
		ft_strcut_toend(str, i);
		i = 0;
		quote = '\0';
		token = malloc(ft_strlen(str) + 1);
		while ((ft_isspace(str[i]) == 0 && str[i] != '|' && str[i] != '<' && str[i] != '>' && str[i] != ';' && str[i] != '&' && str[i] != '\0') || quote != '\0')
		{
			token[i] = str[i];
			if (str[i] == quote)
				quote = '\0';
			else if ((str[i] == '"' || str[i] == '\'') && quote == '\0')
				quote = str[i];
			i++;
		}
		if (i == 0)
		{
			quote = str[0];
			
			while (str[i] == quote)
			{
				token[i] = str[i];
				i++;
			}
			quote = '\0';
		}
		token[i] = '\0';
		ft_strcut_toend(str, i);
		l = ft_lstnew(token);
		if (start == NULL)
			start = l;
		else
			ft_lstadd_back(start, l);
		free(token);
	}
	free(str);
	return (start);
}

//Separa un string en tokens
char	**ft_lexer(char *readl, t_list *envp)
{
	struct s_tokens	tokens;

	//ft_lexer_2(readl);
	tokens.buff = ft_envars(readl, envp);
	tokens.n_tokens = ft_count_tokens(tokens.buff);
	tokens.result = malloc(sizeof(char *) * (tokens.n_tokens + 1));
	tokens.i = 0;
	while (tokens.i < tokens.n_tokens)
	{
		ft_get_next_token(&tokens);
		tokens.i = tokens.i + 1;
	}
	tokens.result[tokens.i] = NULL;
	free(tokens.buff);
	return (tokens.result);
}