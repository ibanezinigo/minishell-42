/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pruebalex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 19:05:04 by ingonzal          #+#    #+#             */
/*   Updated: 2021/12/21 20:45:45 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <./libft.h>

int	ft_count(char *str)
{
	int	i;
	int	pos;

	pos = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '"' || s[i] == ''')
		{
			while (s[i] != '"' || s[i] != ''')
				i++;
			pos++;
		}
		if (s[i] == '<' || s[i] == '>' || s[i] == "|")
		{
			i++;
			if (s[i] == '<' || s[i] == '>')
				i++;
			if (s[i] - 1 != ' ')
			{
				if (s[i] + 1 != ' ')
					pos++;
				pos++;
			}
			pos++;
		}
		if (s[i] == ' ' && s[i] + 1 != ' ')
			pos++;
		i++;
	}
	return (pos + 1);
}

char	**ft_lexer(char *prompt)
{
	int	i;
	char *str;
	char **tab;

	if(!prompt)
		return (NULL);
	str = ft_strtrim(prompt, ' ');
	if (!str)
		return(NULL);
	num = ft_count(str);
	tab = (char **)malloc((num + 1) * sizeof(char *));
	i = 0;
	while (prompt[i])
	{
		if(promt)
		i++;
	}
}

int	main()
{
	char *prompt;

	while (1)
	{
		prompt = readline("Minishell>");
		add_history(prompt);
		ft_lexer(prompt);
	}
	return (0);
}
