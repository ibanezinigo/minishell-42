/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_count_tokens.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iibanez- <iibanez-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 11:23:08 by iibanez-          #+#    #+#             */
/*   Updated: 2021/12/29 11:52:34 by iibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	ft_count_tokens_aux_basic(char c, int *tokens, char lc)
{
	if (c == '|' && lc != '|')
	{
		*tokens = *tokens + 1;
		if (ft_isspace(lc) == 0)
			*tokens = *tokens + 1;
	}
	if (c == ';')
	{
		*tokens = *tokens + 1;
		if (ft_isspace(lc) == 0)
			*tokens = *tokens + 1;
	}
	if (c == '&' && lc != '&')
	{
		*tokens = *tokens + 1;
		if (ft_isspace(lc) == 0)
			*tokens = *tokens + 1;
	}
}

void	ft_count_tokens_aux_advanced(char c, int *tokens, char lc, char q)
{
	if (ft_isspace(c) == 1 && lc != '\0' && ft_isspace(lc) == 0
		&& q == '\0' && lc != '>' && lc != '<' && lc != '|' && lc != '&')
		*tokens = *tokens + 1;
	if ((c == '>' || c == '<') && (lc != '>' && lc != '<'))
	{	
		*tokens = *tokens + 1;
		if (ft_isspace(lc) == 0 && !(lc == '>' || lc == '<'))
			*tokens = *tokens + 1;
	}
}

//Cuenta cuantos tokens existen en la cadena
int	ft_count_tokens(char *str)
{
	int		tokens;
	int		i;
	char	last_char;
	char	quote;

	tokens = 0;
	i = 0;
	last_char = '\0';
	quote = '\0';
	while (str[i])
	{
		ft_count_tokens_aux_advanced(str[i], &tokens, last_char, quote);
		ft_count_tokens_aux_basic(str[i], &tokens, last_char);
		if ((str[i] == 34 || str[i] == 39) && quote == '\0')
			quote = str[i];
		else if (str[i] == quote)
			quote = '\0';
		last_char = str[i];
		i++;
	}
	if (ft_isspace(last_char) == 0 && last_char != '\0'
		&& last_char != '>' && last_char != '<'
		&& last_char != '|' && last_char != '&')
		tokens++;
	return (tokens);
}
