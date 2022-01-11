/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iibanez- <iibanez-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 13:53:15 by iibanez-          #+#    #+#             */
/*   Updated: 2022/01/11 18:17:00 by iibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYNTAX_H
# define SYNTAX_H
# include <stdio.h>
# include "../define/definitions.h"
# include "../utils/utils.h"

int	ft_isvalidquotes(char *str);
int	ft_forbidden_char(char *str);
int	ft_command_checker(t_list **commands);
#endif