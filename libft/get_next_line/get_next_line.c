/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 19:16:24 by ingonzal          #+#    #+#             */
/*   Updated: 2021/09/19 14:49:09 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <unistd.h>
#include <stdlib.h>

int	get_next_line(int fd, char **line)
{	
	char			*buf;
	ssize_t			res;
	static char		*ar;
	int				end;
	int				lel;

	if (fd < 0 || fd > 999 || line == NULL)
		return (-1);
	res = 1;
	buf = (char *)malloc(sizeof (char) + 1);
	while (res > 0 && ft_strchr_gnl(ar, '\n') == NULL)
	{
		res = read(fd, buf, 1);
		buf[res] = '\0';
		ar = ft_strjoin_gnl(ar, buf);
	}
	free(buf);
	end = ft_gnlen(ar, '\n');
	*line = ft_substr_gnl(ar, 0, end);
	lel = ft_gnlen(*line, 0);
	if (res != -1)
		ar = ft_substr2_gnl(ar, (end + 1), (ft_gnlen(ar, 0) - lel));
	if (res > 1)
		res = 1;
	return (res);
}
