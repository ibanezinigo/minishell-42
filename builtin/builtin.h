/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iibanez- <iibanez-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 11:26:06 by iibanez-          #+#    #+#             */
/*   Updated: 2021/12/30 11:26:46 by iibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
#define BUILTIN_H
#include "../list/list.h"
void	ft_cd(t_list *command, char **envp);
void 	ft_pwd();
void	ft_env(char **envp);
void	ft_exit();
void	ft_echo(t_list *command);
#endif