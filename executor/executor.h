/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iibanez- <iibanez-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 11:39:49 by iibanez-          #+#    #+#             */
/*   Updated: 2021/12/30 11:36:33 by iibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H
#include "../list/list.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>
#include "../utils/utils.h"
#include "../builtin/builtin.h"

typedef struct s_execution
{
	int		out[2];
	int		in[2];
	int		redi;
	char	*output;
    char    *input;
}	t_execution;

char	*ft_search_dir(char **path, char *search);
int     ft_execute(t_list **commands, char **envp);
t_list  *ft_delete_token(t_list *command, t_list *act, t_execution *o, int redi);
t_list	*ft_check_output(t_list *command, t_execution *o);
void	ft_die(char *e);

#endif