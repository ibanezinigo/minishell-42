/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iibanez- <iibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 13:13:26 by iibanez-          #+#    #+#             */
/*   Updated: 2022/01/14 16:34:11 by iibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

//USADO
void	ft_freelist2d(t_list **l)
{
	int		i;
	t_list	*tmp;

	i = 0;
	while (l[i])
	{
		tmp = l[i];
		while (tmp)
			tmp = ft_del_node(tmp, 0);
		i++;
	}
	free(l);
}



