/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iibanez- <iibanez-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 18:29:29 by iibanez-          #+#    #+#             */
/*   Updated: 2022/01/11 18:33:52 by iibanez-         ###   ########.fr       */
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
