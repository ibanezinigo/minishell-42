/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_executor_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iibanez- <iibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 09:42:54 by iibanez-          #+#    #+#             */
/*   Updated: 2022/01/12 19:28:34 by iibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

char	*ft_read_dir(char *path, struct dirent *dirp)
{
	char			*tmp;
	char			*result;

	tmp = ft_strcat(path, "/");
	result = ft_strcat(tmp, dirp->d_name);
	free(tmp);
	return (result);
}

char	*ft_search_dir(char **path, char *search)
{
	DIR				*dp;
	struct dirent	*dirp;
	char			*result;

	while (*path)
	{
		dp = opendir(*path);
		if (dp != NULL)
		{
			dirp = readdir(dp);
			while (dirp != NULL)
			{
				if (ft_strequals(search, dirp->d_name))
				{
					result = ft_read_dir(*path, dirp);
					closedir(dp);
					return (result);
				}
				dirp = readdir(dp);
			}
			closedir(dp);
		}
		path++;
	}
	return (NULL);
}

void	ft_print_output(t_execution *exe)
{
	if (exe->redi == -1 && exe->output)
	{
		printf("%s", exe->output);
		free(exe->output);
		exe->output = NULL;
	}
	if (exe->error)
	{
		printf("%s", exe->error);
		free(exe->error);
		exe->error = NULL;
	}
}

void	ft_read_execve(t_execution *exe)
{
	int		nbytes;
	char	*buff;

	buff = malloc(sizeof(char) * 4096);
	nbytes = 1;
	while (nbytes > 0)
	{
		nbytes = read(exe->out[0], buff, 4095);
		buff[nbytes] = '\0';
		if (g_global.errnor != 0)
			exe->error = ft_append_tostr(exe->error, buff);
		else
			exe->output = ft_append_tostr(exe->output, buff);
	}
	free(buff);
}
