/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iibanez- <iibanez-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 20:10:29 by iibanez-          #+#    #+#             */
/*   Updated: 2021/12/21 20:35:27 by iibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include <readline/readline.h>
#include <readline/history.h>

/*
Crear strcmp
*/

//Devuelve el tamaño de un string
int	ft_strlen(char *str)
{
	int	size;

	size = 0;
	while (str[size])
		size = size + 1;
	return (size);
}

//Copia un string en una nueva dirección de memoria
char	*ft_strcpy(char *src)
{
	char	*dest;
	int		i;

	dest = malloc(sizeof(char) * (ft_strlen(src) + 1));
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

//Extrae el siguiente token de la cadena
char	*ft_get_next_token(char *src)
{
	return (NULL);
}

void	ft_count_tokens_aux_basic(char c, int *tokens, char lc)
{
	if (c == '|')
	{
		printf("1");
		*tokens = *tokens + 1;
		if (lc != ' ')
		{
			printf("2");
			*tokens = *tokens + 1;
		}
	}
	if (c == ';')
	{
		printf("3");
		*tokens = *tokens + 1;
		if (lc != ' ')
		{
			printf("4");
			*tokens = *tokens + 1;
		}
	}
}

void	ft_count_tokens_aux_advanced(char c, int *tokens, char lc, char q)
{
	if (c == ' ' && lc != '\0' && lc != ' ' && q == '\0' && lc != '>' && lc != '<' && lc != '|')
	{
		printf("5");
		*tokens = *tokens + 1;
	}
	if ((c == '>' || c == '<') && (lc != '>' && lc != '<'))
	{	
		printf("6");
		*tokens = *tokens + 1;
		if (lc != ' ' && !(lc == '>' || lc == '<'))
		{
			printf("7");
			*tokens = *tokens + 1;
		}
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
		if (str[i] == 34 || str[i] == 39)
			quote = str[i];
		else if (str[i] == quote)
			quote = '\0';
		last_char = str[i];
		i++;
	}
	if (last_char != ' ' && last_char != '\0' && last_char != '>' && last_char != '<' && last_char != '|')
	{
		printf("8");
		tokens++;
	}
	printf("\n");
	return (tokens);
}

//Separa un string en tokens
char	**ft_lexer(char *readl)
{
	char	*buff;
	char	**result;
	int		i;

	buff = ft_strcpy(readl);
	while (buff != NULL)
	{
		i = 0;
	}
	free(buff);
	return (NULL);
}

int	main(void)
{
	char	*readl;

	readl = readline("test> ");
	while (readl[0] != 'e')
	{
		add_history(readl);
		printf("%s\n", readl);
		printf("%i\n", ft_count_tokens(readl));
		readl = readline("test> ");
	}
	return (0);
}
