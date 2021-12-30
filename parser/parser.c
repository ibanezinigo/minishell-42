/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 16:43:02 by ingonzal          #+#    #+#             */
/*   Updated: 2021/12/30 13:41:36 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <unistd.h>

int	ft_pipe_counter(char **lexer)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (lexer[i] != NULL)
	{
		if (lexer[i][0] == 124)
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
	while (i < size)
	{
		if (lexer[i][0] != 124)
			j++;
		if (lexer[i][0] == 124)
		{
			toknum[i] = j;
			j = 0;
		}
		i++;
	}
	toknum[i] = '\0';
	return (toknum);
}

void	ft_free(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

char	***ft_parser(char **lexer)
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
	j = 0;
	while (i < (y + 1))
	{
		par[i] = (char **)malloc((toknum[i] * 1) * sizeof(char *));
		while (j < toknum[i])
		{
			par[i][j] = lexer[i];
			j++;
		}
		par[i][j] = NULL;
		j = 0;
		i++;
	}
	par[i] = NULL;
	ft_free(lexer);
	free(toknum);
	return (par);
}

int	main(void)
{
	/* char	array[3][10] = {"a", "|", "b"}; */
	char	**array;
	char	***res;
	int		i;
	int		j;
	int		k;

	array = (char **)malloc(7 * sizeof(char *));
	i = 0;
	while (i < 6)
	{
		array[i] = (char *)malloc(1 * sizeof(char));
		i++;
	}
	array[i] = NULL;
	array[0][0] = 'i';
	array[1][0] = 'j';
	array[2][0] = 'o';
	array[3][0] = 124;
	array[4][0] = 'p';
	array[5][0] = 'i';

	res = ft_parser(array);
	i = 0;
	j = 0;
	k = 0;
	while (res[i][j][k] != '\0')
	{
		while (res[i][j][k] != '\0')
		{
			while (res[i][j][k] != '\0')
			{
				write(1, &res[i][j][k], 1);
				k++;
			}
			write(1, " ", 1);
			k = 0;
			j++;
		}
		write(1, "\n", 1);
		j = 0;
		i++;
	}
	return (0);
}
