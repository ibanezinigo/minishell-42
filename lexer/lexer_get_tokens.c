/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_get_tokens.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iibanez- <iibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 20:10:29 by iibanez-          #+#    #+#             */
/*   Updated: 2022/01/12 20:23:49 by iibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	ft_get_quoted_2(struct s_tokens *tokens, int *i, int *j, char *quote)
{
	while (tokens->buff[*i + *j] != *quote)
	{
		tokens->result[tokens->i][*j] = tokens->buff[*i + *j];
		*j = *j + 1;
	}
	if (tokens->buff[*i + *j + 1] != '\"' && tokens->buff[*i + *j + 1] != '\'')
	{
		*quote = '\0';
		*i = *i + 1;
	}
	else
	{
		*quote = tokens->buff[*i + *j + 1];
		*i = *i + 2;
	}
}

void	ft_get_quotedaux(struct s_tokens *tokens, int *i, int *j, char *quote)
{
	if (tokens->buff[*i + *j] == *quote)
	{
		*quote = '\0';
		*i = *i + 1;
	}
	else if (tokens->buff[*i + *j] == '"' || tokens->buff[*i + *j] == '\'')
	{
		*quote = tokens->buff[*i + *j];
		*i = *i + 1;
	}
	else
	{
		tokens->result[tokens->i][*j] = tokens->buff[*i + *j];
		*j = *j + 1;
	}
}

void	ft_get_quoted(struct s_tokens *tokens)
{
	int		i;
	int		j;
	char	quote;

	tokens->result[tokens->i] = malloc(sizeof(char)
			* ft_strlen(tokens->buff) + 1);
	tokens->result[tokens->i][0] = '\0';
	i = 0;
	while (ft_isspace(tokens->buff[i]))
		i++;
	quote = tokens->buff[i];
	i++;
	j = 0;
	while (quote != '\0')
		ft_get_quoted_2(tokens, &i, &j, &quote);
	while (tokens->buff[i + j] != '\0' && ft_isspace(tokens->buff[i + j]) == 0
		&& (ft_special_char(tokens->buff[i + j]) && quote == '\0') == 0)
		ft_get_quotedaux(tokens, &i, &j, &quote);
	tokens->result[tokens->i][j] = '\0';
	if (tokens->buff[i + j] == '\0')
		tokens->buff[0] = '\0';
	else
		ft_strcut_toend(tokens->buff, i + j + 1);
}

void	ft_get_special_token(struct s_tokens *tokens)
{
	int	i;
	int	j;

	i = 0;
	while (ft_isspace(tokens->buff[i]))
		i++;
	j = 0;
	while (ft_special_char(tokens->buff[i + j]))
		j++;
	tokens->result[tokens->i] = malloc(sizeof(char) * j + 1);
	j = 0;
	while (ft_special_char(tokens->buff[i + j]))
	{
		tokens->result[tokens->i][j] = tokens->buff[i + j];
		j++;
	}
	tokens->result[tokens->i][j] = '\0';
	ft_strcut_toend(tokens->buff, i + j);
}

//Extrae el siguiente token de la cadena
void	ft_get_next_token(struct s_tokens *tokens)
{
	int		i;

	i = 0;
	while (ft_isspace(tokens->buff[i]))
		i++;
	if ((tokens->buff[i] == 34 || tokens->buff[i] == 39))
	{
		ft_get_quoted(tokens);
	}
	else if (tokens->buff[i] == '<' || tokens->buff[i] == '>'
		|| tokens->buff[i] == '|' || tokens->buff[i] == '&')
	{
		ft_get_special_token(tokens);
	}
	else if (ft_isspace(tokens->buff[i]) == 0)
	{
		ft_get_normal_string(tokens);
	}
}
