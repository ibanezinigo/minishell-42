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
void	ft_cd(char *argv[], char **envp);
void 	ft_pwd(char *argv[], char **envp);
void	ft_env(char *argv[], char **envp);
void	ft_exit();
void	ft_echo(char *argv[], char **envp);
#endif