/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iibanez- <iibanez-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 11:54:45 by iibanez-          #+#    #+#             */
/*   Updated: 2021/12/30 09:47:26 by iibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include <stdlib.h>

void	ft_strcut_toend(char *str, int from);
int		ft_strequals(char *str1, char *str2);
int		ft_isspace(char c);
int		ft_special_char(char c);
int		ft_strlen(char *str);
char	*ft_strcpy(char *src);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strcat(char *dst, char *src);
int		ft_strcontainstext(char *str);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
int		ft_isalnum(int c);
#endif