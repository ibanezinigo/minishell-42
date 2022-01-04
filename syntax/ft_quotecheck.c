/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quotecheck.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iibanez- <iibanez-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 13:48:32 by iibanez-          #+#    #+#             */
/*   Updated: 2022/01/04 13:57:10 by iibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isvalidquotes(char *str)
{
	char	quote;
	int		i;

	i = 0;
	quote = '\0';
	while (str[i])
	{
		if (quote == '\0' && (str[i] == '\'' || str[i] == '\"'))
			quote = str[i];
		else if (str[i] == quote)
			quote = '\0';
		i++;
	}
	if (quote != '\0')
		return (0);
	return (1);
}