/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   definitions.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iibanez- <iibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 13:22:46 by iibanez-          #+#    #+#             */
/*   Updated: 2022/01/13 15:50:12 by iibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINITIONS_H
# define DEFINITIONS_H

typedef struct s_list
{
	char			*token;
	struct s_list	*next;
}	t_list;

typedef struct s_execution
{
	int		out[2];
	int		in[2];
	int		redi;
	int		in_redi;
	char	*outputfile;
	char	*output;
	char	*input;
	char	*error;
	t_list	**envp2;
}	t_execution;

typedef struct s_global
{
	int	errnor;
	int	pid;
}	t_global;

t_global	g_global;
#endif