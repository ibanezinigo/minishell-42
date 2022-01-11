/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syntaxchecker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iibanez- <iibanez-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 13:48:32 by iibanez-          #+#    #+#             */
/*   Updated: 2022/01/11 18:21:48 by iibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "syntax.h"

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
	{
		printf("-bash: quotes not closed.\n");
		return (0);
	}
	return (1);
}

int	ft_forbidden_char(char *str)
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
		if (quote == '\0' && (str[i] == ';' || str[i] == '&'
				|| str[i] == '*' || str[i] == '\\'))
		{
			printf("-bash: %c not supported.\n", str[i]);
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_forbiden_redirection(char *str)
{
	if (ft_strstartwith(str, "<<<"))
		printf("-bash: syntax error near unexpected token `<<<'\n");
	else if (ft_strstartwith(str, "<<"))
		printf("-bash: syntax error near unexpected token `<<'\n");
	else if (ft_strstartwith(str, "<"))
		printf("-bash: syntax error near unexpected token `<'\n");
	else if (ft_strstartwith(str, ">>"))
		printf("-bash: syntax error near unexpected token `>>'\n");
	else if (ft_strstartwith(str, ">"))
		printf("-bash: syntax error near unexpected token `>'\n");
	else if (ft_strstartwith(str, "|"))
		printf("-bash: syntax error near unexpected token `|'\n");
	else
		return (0);
	return (1);
}

int	ft_check_error(t_list *act, t_list **commands, int *i)
{
	if (ft_strequals(act->token, "<") || ft_strequals(act->token, "<<")
		|| ft_strequals(act->token, ">") || ft_strequals(act->token, ">>"))
	{
		if (!act->next)
		{
			printf("-bash: syntax error near unexpected token `newline'\n");
			return (0);
		}
		else if (ft_forbiden_redirection(act->next->token))
			return (0);
	}
	if (ft_strequals(act->token, "|") && commands[*i + 1] == NULL)
	{
		printf("-bash: syntax error near unexpected token `|'\n");
		return (0);
	}
	return (1);
}

int	ft_command_checker(t_list **commands)
{
	t_list	*act;
	int		i;

	i = 0;
	while (commands[i])
	{
		act = commands[i];
		while (act)
		{
			if (ft_check_error(act, commands, &i) == 0)
				return (0);
			act = act->next;
		}
		i++;
	}
	return (1);
}
