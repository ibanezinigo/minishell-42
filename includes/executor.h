/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iibanez- <iibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 11:39:49 by iibanez-          #+#    #+#             */
/*   Updated: 2022/01/12 21:15:10 by iibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H
# include "definitions.h"
# include "builtin.h"
# include "list.h"
# include "utils.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <dirent.h>
# include <errno.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "syntax.h"

char	*ft_search_dir(char **path, char *search);
int		ft_execute(t_list **commands, t_execution *e);
t_list	*ft_delete_token(t_list *command,
			t_list *act, t_execution *o, int redi);
t_list	*ft_check_output(t_list *command, t_execution *o);
void	ft_redirect_output(t_execution *exe);
t_list	*ft_check_input(t_list *command, t_execution *o);
void	ft_die(char *e);
void	ft_print_output(t_execution *exe);
void	ft_read_execve(t_execution *exe);
#endif