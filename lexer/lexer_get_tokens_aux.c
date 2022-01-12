/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_get_tokens_aux.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iibanez- <iibanez-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 19:27:42 by iibanez-          #+#    #+#             */
/*   Updated: 2022/01/11 19:28:49 by iibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	ft_get_string(int *quote, struct s_tokens *tokens, int *i, int *j)
{
	if (*quote == '\0' && (tokens->buff[*i + *j] == '\''
			|| tokens->buff[*i + *j] == '\"'))
	{
		*quote = tokens->buff[*i + *j];
		*i = *i + 1;
	}
	else if (*quote == tokens->buff[*i + *j])
	{
		*quote = '\0';
		*i = *i + 1;
	}
	else
	{
		tokens->result[tokens->i][*j] = tokens->buff[*i + *j];
		*j = *j + 1;
	}
}

void	ft_get_normal_string(struct s_tokens *tokens)
{
	int		i;
	int		j;
	int		quote;

	i = 0;
	while (tokens->buff[i] != '\0')
		i++;
	tokens->result[tokens->i] = malloc(sizeof(char) * (i + 1));
	i = 0;
	while (ft_isspace(tokens->buff[i]))
		i++;
	j = 0;
	quote = '\0';
	while (tokens->buff[i + j] != '\0' && ft_isspace(tokens->buff[i + j]) == 0
		&& ft_special_char(tokens->buff[i + j]) == 0)
	{
		ft_get_string(&quote, tokens, &i, &j);
	}
	tokens->result[tokens->i][j] = '\0';
	ft_strcut_toend(tokens->buff, i + j);
}
