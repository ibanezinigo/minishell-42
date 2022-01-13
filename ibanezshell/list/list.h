/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iibanez- <iibanez-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 09:47:50 by iibanez-          #+#    #+#             */
/*   Updated: 2022/01/04 13:23:23 by iibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include "../utils/utils.h"
# include <unistd.h>

t_list	*ft_lstnew(char *str);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list *last, t_list *new);
t_list	**ft_table_to_list(char *table[], t_list **commands);
t_list	*ft_del_node(t_list *start, int del);
int		ft_node_position(t_list *start, t_list *find);
void	ft_print_list(t_list *start);
char	**ft_listtotable(t_list *lst);
char	*ft_getenv_value(t_list *env, char *str);

#endif