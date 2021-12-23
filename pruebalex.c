/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pruebalex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 19:05:04 by ingonzal          #+#    #+#             */
/*   Updated: 2021/12/22 14:13:45 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "./libft/libft.h"

int	ft_count(char *str)
{
	int	i;
	int	pos;

	pos = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '"' || str[i] == ''')
		{
			while (str[i] != '"' || str[i] != ''')
				i++;
			pos++;
		}
		if (str[i] == '<' || str[i] == '>' || str[i] == "|")
		{
			i++;
			if (str[i] == '<' || str[i] == '>')
				i++;
			if (str[i - 1] != ' ')
			{
				if (str[i + 1] != ' ')
					pos++;
				pos++;
			}
			pos++;
		}
		if (str[i] == ' ' && str[i + 1] != ' ')
			pos++;
		i++;
	}
	return (pos + 1);
}

void	*ft_free(char **tab, int pos, char *str)
{
	while (pos)
		free (tab[--pos]);
	free (tab);
	free (str);
	return (NULL);
}

char	**ft_instr(char **tab, char *str)
{
	int count;
	int	len;
	int	pos;

	pos = 0;
	len	= 0;
	count = -1;
	while (str[++count])
	{
		if (str[count] != ' ')
		{
			len++;
			if (str[count + 1] == ' ' || str[count + 1] == '\0')
			{
				tab[pos] = ft_substr(str, (count - len) + 1, len);
				if (!tab[pos])
					return (ft_free(tab, pos, str));
				pos++;
				len = 0;
			}
		}
	}
	tab[pos] = NULL;
	free(str);
	return (tab);
}

char	**ft_lexer(char *prompt)
{
	int	i;
	char *str;
	char **tab;

	if (!prompt)
		return (NULL);
	str = ft_strtrim(prompt, ' ');
	if (!str)
		return(NULL);
	num = ft_count(str);
	tab = (char **)malloc((num + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	return (ft_lexer(tab, str));
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
