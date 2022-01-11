/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iibanez- <iibanez-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 12:53:44 by iibanez-          #+#    #+#             */
/*   Updated: 2022/01/11 11:42:37 by iibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_strcut_toend(char *str, int from)
{
	int	i;

	i = 0;
	while (str[from + i])
	{
		str[i] = str[from + i];
		i++;
	}
	str[i] = str[from + i];
}

int	ft_strequals(char *str1, char *str2)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	if (ft_strlen(str1) != ft_strlen(str2))
		return (0);
	while (str1[i])
	{
		if (str1[i] != str2[i])
			return (0);
		i++;
	}
	return (1);
}

//Devuelve 1 si contiene un caractes de espaciado, si no 0
int	ft_isspace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

int	ft_special_char(char c)
{
	if (c == '<' || c == '>' || c == '|' || c == '&' || c == ';')
		return (1);
	return (0);
}

#include <stdio.h>
//Devuelve el tamaño de un string
int	ft_strlen(char *str)
{
	int	size;

	if (!str)
		return (0);
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
	dest[i] = '\0';
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	t_len;
	size_t	i;
	char	*dst;

	if (!s)
		return (NULL);
	dst = malloc (sizeof(char) * (len + 1));
	if (dst == NULL)
		return (NULL);
	i = 0;
	t_len = 0;
	while (s[i])
	{
		if (i >= start && t_len < len)
		{
			dst[t_len] = s[i];
			t_len++;
		}
		i++;
	}
	dst[t_len] = 0;
	return (dst);
}

char	*ft_strcat(char *dst, char *src)
{
	int		i;
	int		j;
	char	*result;

	result = malloc(sizeof(char) * (ft_strlen(dst) + ft_strlen(src) + 1));
	i = 0;
	while (dst && dst[i])
	{
		result[i] = dst[i];
		i++;
	}
	j = 0;
	while (src && src[j])
	{
		result[i + j] = src[j];
		j++;
	}
	result[i + j] = '\0';
	return (result);
}

int	ft_strcontainstext(char *str)
{
	int	i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i])
	{
		if (ft_isspace(str[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	return (0);
}

int	ft_strisalnum(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isalnum(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_parser_count_commands(char **src)
{
	int	i;
	int	result;

	result = 1;
	i = 0;
	while (src[i])
	{
		if (ft_strequals(src[i], "|"))
			result++;
		i++;
	}
	return (result);
}

char	*ft_getenv(t_list *l, char *path)
{
	int		j;
	char	*value;
	t_list	*next;

	next = l;
	while (next)
	{
		value = next->token;
		j = 0;
		while (path[j])
		{
			if (value[j] != path[j])
				break ;
			j++;
		}
		if (value[j] == '=' && path[j] == '\0')
			return (&value[j + 1]);
		next = next->next;
	}
	return (NULL);
}

char *ft_append_tostr(char *str, char *str2)
{
	char *tmp;

	tmp = ft_strcat(str, str2);
	free(str);
	return (tmp);
}

int	ft_strstartwith(char *s1, char *s2)
{
	int	i;

	if (!s1 || !s2)
		return (0);
	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	long	i;
	long	nbr;
	int		isneg;

	i = 0;
	nbr = 0;
	isneg = 0;
	while (str[i] != '\0' && (str[i] == 32 || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] != '\0' && str[i] == '-')
	{
		isneg = 1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] != '\0' && ft_isdigit(str[i]))
		nbr = (nbr * 10) + (str[i++] - '0');
	if (isneg == 1)
		return (-nbr);
	return (nbr);
}