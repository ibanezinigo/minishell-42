/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_executor_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iibanez- <iibanez-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 09:42:54 by iibanez-          #+#    #+#             */
/*   Updated: 2022/01/03 17:57:31 by iibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

char	*ft_search_dir(char **path, char *search)
{
	DIR				*dp;
	struct dirent	*dirp;
	char			*tmp;
	char			*result;

	while (*path)
	{
		dp = opendir(*path);
		dirp = readdir(dp);
		while (dirp != NULL)
		{
			if (ft_strequals(search, dirp->d_name))
			{
				tmp = ft_strcat(*path, "/");
				result = ft_strcat(tmp, dirp->d_name);
				free(tmp);
				closedir(dp);
				return (result);
			}
			dirp = readdir(dp);
		}
		path++;
	}
	closedir(dp);
	return (NULL);
}

void	ft_die(char *e)
{
	fprintf(stderr, "bash: %s: command not found\n", e);
	exit(EXIT_FAILURE);
}
