/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iibanez- <iibanez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 11:54:45 by iibanez-          #+#    #+#             */
/*   Updated: 2022/01/14 16:04:26 by iibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include <stdlib.h>
# include "definitions.h"
# include "list.h"

void	ft_strcut_toend(char *str, int from);
int		ft_strequals(char *str1, char *str2);
int		ft_isspace(char c);
int		ft_special_char(char c);
int		ft_strlen(char *str);
char	*ft_strcpy(char *src);
char	**ft_split(char const *s, char c);
void	ft_free_list(char **list);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strcat(char *dst, char *src);
int		ft_strcontainstext(char *str);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
int		ft_isalnum(int c);
int		ft_strisalnum(char *str);
int		ft_parser_count_commands(char **src);
char	*ft_getenv(t_list *l, char *path);
char	*ft_append_tostr(char *str, char *str2);
char    *ft_append_ctostr(char *str, char c);
int		ft_strstartwith(char *s1, char *s2);
int		ft_atoi(const char *str);
char	*ft_itoa(int n);
int		ft_isdigit(int c);
int		ft_isalpha(int c);
void	ft_str_to_lower(char *str);
void	ft_freelist2d(t_list **l);
void	ft_freelist1d(t_list *l);
void	ft_freecharlist(char **l);
#endif
