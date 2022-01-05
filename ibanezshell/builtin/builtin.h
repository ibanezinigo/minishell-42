/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iibanez- <iibanez-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 13:19:02 by iibanez-          #+#    #+#             */
/*   Updated: 2022/01/04 13:36:40 by iibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H
# include "../define/definitions.h"
# include "../utils/utils.h"
# include "../list/list.h"
void	ft_echo(t_list *command, t_execution *exe);
void	ft_export(t_list *command, t_execution *exe);
void	ft_unset(t_list *command, t_execution *exe);
void	ft_env(t_execution *exe);
void	ft_pwd(t_execution *exe);
void	ft_cd(t_list *command, t_execution *exe);
void 	ft_pwd(t_execution *exe);
void	ft_exit(void);
#endif