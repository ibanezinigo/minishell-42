/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iibanez- <iibanez-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 12:53:44 by iibanez-          #+#    #+#             */
/*   Updated: 2021/12/22 13:11:16 by iibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>


//Devuelve 1 si contiene un caractes de espaciado, si no 0
int	ft_isspace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' | c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

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