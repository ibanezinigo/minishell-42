/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iibanez- <iibanez-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 13:30:45 by iibanez-          #+#    #+#             */
/*   Updated: 2022/01/11 11:03:54 by iibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	ft_pwd(t_execution *exe)
{
	char	*result;

	result = malloc(sizeof(char) * 2500);
	getcwd(result, 2500);
	exe->output = ft_strcat(result, "\n");
	g_errno = 0;
	free(result);
}