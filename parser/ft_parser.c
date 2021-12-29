/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iibanez- <iibanez-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 19:13:20 by iibanez-          #+#    #+#             */
/*   Updated: 2021/12/29 19:19:52 by iibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/utils.h"

char ***ft_parser(char **src)
{
	char	dst[500][500][500];
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (src[i] != NULL)
	{
		if (ft_strequal(src[i] == "|"))
		{
			dst[j][k] = NULL;
			j++;
			k = 0;
		}
		else
		{
			dst[j][k] = src[i];
			k++;
		}
		i++;
	}
	dst[j][k] = NULL;

	return (dst);
}