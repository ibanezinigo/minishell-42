/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iibanez- <iibanez-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 14:18:45 by iibanez-          #+#    #+#             */
/*   Updated: 2021/12/28 10:37:53 by iibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

unsigned int	ft_count_words(char const *s, char c)
{
	unsigned int	i;
	unsigned int	nstr;

	if (!s[0])
		return (0);
	i = 0;
	nstr = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			nstr++;
			while (s[i] && s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] != c)
		nstr++;
	return (nstr);
}

void	ft_free_list(char **list)
{
	int	i;

	i = 0;
	while (list[i])
	{
		free(list[i]);
		i++;
	}
	free(list);
}

void	ft_save_words(char const *s, char c, char **list)
{
	int	i;
	int	j;
	int	words;

	i = 0;
	words = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		j = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		if (j != i)
		{
			list[words] = ft_substr(s, j, i - j);
			if (list[words] == NULL)
				ft_free_list(list);
			words++;
		}
	}
}

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**list;

	if (!s)
		return (NULL);
	words = ft_count_words(s, c);
	list = malloc(sizeof(*list) * (words + 1));
	if (!list)
		return (NULL);
	if (words > 0)
		ft_save_words(s, c, list);
	list[words] = NULL;
	return (list);
}