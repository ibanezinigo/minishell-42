/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iibanez- <iibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 18:30:56 by iibanez-          #+#    #+#             */
/*   Updated: 2022/01/14 16:33:12 by iibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

//USADO
char	*ft_strcpy(char *src)
{
	char	*dest;
	int		i;

	if (!src)
		return (NULL);
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

//USADO
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
