/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 16:43:02 by ingonzal          #+#    #+#             */
/*   Updated: 2021/12/28 18:13:03 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_pipe_counter(char **lexer)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(lexer[i] != NULL)
	{
		if(lexer[i] == 124)
			j++;
		i++;
	}
	return (j + 1);
}

int	*ft_token_counter(char **lexer, int size)
{
	int	i;
	int	j;
	int	*toknum;

	i = 0;
	j = 0;
	toknum = (int *)malloc((size + 1) * sizeof(int));
	while(i < size)
	{
		if(lexer[i] != 124)
			j++;
		if(lexer[i] == 124)
		{
			toknum[i] = j;
			j = 0;
		}
		i++;
	}
	toknum[i] = NULL;
	return(toknum);
}

char ***ft_parser(char	**lexer)
{
	int		y;
	int		i;
	int		j;
	char	***par;
	int		*toknum;

	y = ft_pipe_counter(lexer);
	toknum = ft_token_counter(lexer, y);
	par = (char ***)malloc((y + 1) * sizeof(char **));
	i = 0;
	while (i < (y + 1))		
	{
		par[i] = (char **)malloc((toknum[i] * 1) * sizeof(char *));
		while (j < toknum[i])
		{
			par[i][j] =  lexer[i];
			j++;
		}
		par[i][j] = NULL;
		j = 0;
		i++;
	}
}
