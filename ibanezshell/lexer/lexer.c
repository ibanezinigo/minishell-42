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

//USADO
t_list	*ft_lexer(char *readl)
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
