/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pruebalex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 19:05:04 by ingonzal          #+#    #+#             */
/*   Updated: 2022/01/13 19:43:42 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "libft/libft.h"
#include "../../lexer/lexer.h"

int	ft_count(char *str)
{
	int	i;
	int	pos;

	pos = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == 34)
		{
			/* if (str[i - 1] != ' ') */
				/* i++; */
			while (str[i] != 34 && str[i] != '\0')
				i++;
			pos++;
		}
		if (str[i] == 39)
		{
			i++;
			while (str[i] != 39)
				i++;
			pos++;
		}
		if (str[i] == '<' || str[i] == '>' || str[i] == 124)
		{
			i++;
			if (str[i] == '<' || str[i] == '>')
				i++;
			/* if (str[i - 1] != ' ') */
			/* { */
				/* if (str[i + 1] != ' ') */
				/* 	pos++; */
				/* pos++; */
			/* } */
			pos++;
		}
		if (str[i] == ' '/* && str[i + 1] != ' '*/)
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

int	ft_quote_size(char *s, char q)
{
	int i;

	i = 1;
	while (s[i] != q)
		i++;
	return (i - 1);
}

char	**ft_instr(char **tab, char *s)
{
	char q;
	int i;
	int	len;
	int	pos;

	pos = 0;
	len	= 0;
	i = -1;
	while (s[++i])
	{
		if ((s[i] == 34 || s[i] == 39))
		{
			q = s[i];
			i++;
			if (s[i] != '\0')
			{
				len = ft_quote_size(s, q);
				printf("%d\n", len);
				if (s[i + 1] == ' ' || s[i + 1] == '\0')
				{
					tab[pos] = ft_substr(s, i, len);
					if (!tab[pos])
						return (ft_free(tab, pos, s));
					pos++;
					i += len;
					len = 0;
				}
			}
		}
		else if (s[i] != '\0')
		{
			len++;
			if (s[i + 1] == ' ' || s[i + 1] == '\0' || s[i + 1] == 34 || s[i + 1] == 39)
			{
				/* i++; */
				tab[pos] = ft_substr(s, (i - len) + 1, len);
				if (!tab[pos])
					return (ft_free(tab, pos, s));
				pos++;
				len = 0;
			}
		}
		i++;
	}
	tab[pos] = NULL;
	free(s);
	return (tab);
}

char	**ft_lexer(char *prompt)
{
	/* int		i; */
	int		num;
	char 	*str;
	char 	**tab;
	char	set[2];

	set[0] = ' ';
	set[1] = '\0';
	if (!prompt)
		return (NULL);
	str = ft_strtrim(prompt, set);
	if (!str)
		return(NULL);
	num = ft_count(str);
	tab = (char **)malloc((num + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	return (ft_instr(tab, str));
}
