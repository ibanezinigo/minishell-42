/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iibanez- <iibanez-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 11:54:45 by iibanez-          #+#    #+#             */
/*   Updated: 2022/01/11 11:40:01 by iibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include <stdlib.h>
# include "../define/definitions.h"
# include "../list/list.h"

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
int	    ft_parser_count_commands(char **src);
char	*ft_getenv(t_list *l, char *path);
char 	*ft_append_tostr(char *str, char *str2);
int		ft_strstartwith(char *s1, char *s2);
int		ft_atoi(const char *str);
char	*ft_itoa(int n);
int		ft_isdigit(int c);
int		ft_isalpha(int c);


#endif