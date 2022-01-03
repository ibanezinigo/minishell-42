/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iibanez- <iibanez-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 11:39:49 by iibanez-          #+#    #+#             */
/*   Updated: 2022/01/03 19:45:03 by iibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H
# include "../list/list.h"
# include "../utils/utils.h"
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

typedef struct s_execution
{
	int		out[2];
	int		in[2];
	int		redi;
	int		in_redi;
	char	*outputfile;
	char	*output;
	char	*input;
	char	**envp;
	char	*error;
}	t_execution;

char	*ft_search_dir(char **path, char *search);
int		ft_execute(t_list **commands, char **envp, t_execution *e);
t_list	*ft_delete_token(t_list *command, t_list *act, t_execution *o, int redi);
t_list	*ft_check_output(t_list *command, t_execution *o);
void	ft_redirect_output(t_execution *exe);
t_list	*ft_check_input(t_list *command, t_execution *o);

void	ft_die(char *e);

void	ft_cd(t_list *command, char **envp);
void 	ft_pwd(t_execution *exe);
void	ft_env(t_execution *exe);
void	ft_exit();
void	ft_echo(t_list *command, t_execution *exe);
void	ft_export(t_list *command, t_execution *exe);

#endif