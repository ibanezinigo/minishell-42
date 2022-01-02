#include "executor.h"

char	*ft_search_dir(char **path, char *search)
{
	DIR				*dp;
	struct dirent	*dirp;
	char			*tmp;
	char			*result;

	while (*path)
	{
		dp = opendir(*path);
		dirp = readdir(dp);
		while (dirp != NULL)
		{
			if (ft_strequals(search, dirp->d_name))
			{
				tmp = ft_strcat(*path, "/");
				result = ft_strcat(tmp, dirp->d_name);
				free(tmp);
				closedir(dp);
				return (result);
			}
			dirp = readdir(dp);
		}
		path++;
	}
	closedir(dp);
	return (NULL);
}

t_list	*ft_delete_token(t_list *command, t_list *act, t_execution *o, int redi)
{
	int	i;

	o->redi = redi;
	o->output = ft_strcpy(act->next->token);
	i = ft_node_position(command, act);
	command = ft_del_node(command, i);
	command = ft_del_node(command, i);
	return (command);
}

t_list	*ft_check_output(t_list *command, t_execution *o)
{
	t_list		*act;
	t_list		*next;
	
	o->redi = -1;
	act = command;
	while (act)
	{
		if (ft_strequals(act->token,">"))
		{
			next = act->next->next;
			command = ft_delete_token(command, act, o, 1);
			act = next;
		}		
		else if (ft_strequals(act->token,">>"))
		{
			next = act->next->next;
			command = ft_delete_token(command, act, o, 2);
			act = next;
		}
		else if (ft_strequals(act->token,"|") && o->redi == -1)
		{
			o->redi = 0;
			command = ft_del_node(command, ft_node_position(command, act));
			act = act->next;
		}
		else
			act = act->next;
	}
	return (command);
}

void	ft_die(char *e)
{
	fprintf(stderr, "bash: %s: command not found\n", e);
	exit(EXIT_FAILURE);
}