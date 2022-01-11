/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   definitions.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iibanez- <iibanez-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 13:22:46 by iibanez-          #+#    #+#             */
/*   Updated: 2022/01/10 17:41:40 by iibanez-         ###   ########.fr       */
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

int	g_errno;
#endif