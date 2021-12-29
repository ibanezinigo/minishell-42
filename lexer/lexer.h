/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iibanez- <iibanez-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 11:49:12 by iibanez-          #+#    #+#             */
/*   Updated: 2021/12/29 11:49:48 by iibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "../utils/utils.h"
# include <stdlib.h>

struct s_tokens {
	char	*buff;
	char	**result;
	int		n_tokens;
	int		i;
} t_tokens;

char	**ft_lexer(char *readl);
void	ft_get_next_token(struct s_tokens *tokens);
int		ft_count_tokens(char *str);

#endif