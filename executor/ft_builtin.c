/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iibanez- <iibanez-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 11:25:53 by iibanez-          #+#    #+#             */
/*   Updated: 2022/01/03 19:57:17 by iibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

void	ft_cd(t_list *command, t_execution *exe)
{
	int		result;
	char	**envp;

	envp = ft_listtotable(exe->envp2[0]);
	if (command->next == NULL)
		result = chdir(ft_getenv(envp, "HOME"));
	else if (ft_strequals(command->next->token, "~"))
		result = chdir(ft_getenv(envp, "HOME"));
	else
		result = chdir(command->next->token);
	if (result == -1)
		printf("-bash: cd: %s: %s\n", command->next->token, strerror(errno));
}

void	ft_pwd(t_execution *exe)
{
	char	*result;

	result = malloc(sizeof(char) * 2500);
	getcwd(result, 2500);
	exe->output = ft_strcat(result, "\n");
	free(result);
}

void	ft_env(t_execution *exe)
{
	t_list	*tmp;

	tmp = exe->envp2[0];
	exe->output = malloc(1);
	exe->output[0] = '\0';
	while (tmp)
	{
		exe->output = ft_append_tostr(exe->output, tmp->token);
		exe->output = ft_append_tostr(exe->output, "\n");
	}
}

void	ft_exit(void)
{
	exit(EXIT_SUCCESS);
}

void	ft_echo(t_list *command, t_execution *exe)
{
	int		j;
	int		start;
	int		n;
	t_list	*tmp;

	start = 0;
	n = 0;
	tmp = command->next;
	while (tmp != NULL)
	{
		if (start == 1)
			exe->output = ft_append_tostr(exe->output, " ");
		if (start == 0 && tmp->token[0] == '-' && ft_strlen(tmp->token) > 1)
		{
			j = 1;
			while (tmp->token[j])
			{
				if (tmp->token[j] != 'n')
					start = 1;
				j++;
			}
			if (start == 0 && ft_strlen(tmp->token) > 1)
				n = 1;
		}
		else
			start = 1;
		if (start == 1)
			exe->output = ft_append_tostr(exe->output, tmp->token);
		tmp = tmp->next;
	}
	if (n == 0)
		exe->output = ft_append_tostr(exe->output, "\n");
}

void	ft_export(t_list *command, t_execution *exe)
{
	/*char **tokens;

	tokens = ft_split(command->next->token, '=');
	printf("%s\n", command->token);
	printf("%s\n", command->next->token);
	printf("%s\n", tokens[0]);
	printf("%s\n", tokens[1]);
	if (tokens[1])
	{
		ft_getenv(exe->envp, tokens[0]);
	}*/
}