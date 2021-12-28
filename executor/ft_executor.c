#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include "../utils/utils.h"

#define die(e) do {fprintf(stderr, "bash: %s: command not found\n", e); exit(EXIT_FAILURE);} while (0);

char	*ft_search_dir(char **path, char *search)
{
	int				i;
	DIR				*dp;
	struct dirent	*dirp;
	char			*tmp;
	char			*result;

	i = 0;
	while (path[i])
	{
		dp  = opendir(path[i]);
		while ((dirp = readdir(dp)) != NULL)
			if (ft_strequals(search,dirp->d_name))
			{
				tmp = ft_strcat(path[i], "/");
				result = ft_strcat(tmp, dirp->d_name);
				free(tmp);
				closedir(dp);
				return (result);
			}
		i++;
	}
	closedir(dp);
	return (NULL);
}

int ft_execute(char *argv[], char **envp2)
{
    int		link[2];
    pid_t	pid;
    char	foo[4096];
	char	*path;

	char **envp = ft_split(getenv("PATH"), ':');//{ NULL };,
	path = ft_search_dir(envp, argv[0]);
	//printf("PATH->%s\n", path);

    if (pipe(link)==-1)
        die("pipe");
    
    if ((pid = fork()) == -1)
        die("fork");

    if (pid == 0)
    {
        dup2 (link[1], STDOUT_FILENO);
        close(link[0]);
        close(link[1]);  		
		execve(path, argv, envp2);
        die(argv[0]);
    }
    else
    {
        close (link[1]);
        int nbytes = read(link[0], foo, sizeof(foo));
        printf("%.*s", nbytes, foo);
        wait(NULL);
    }
    return (0);
}

/*
int	main(int argc, char **argv, char **envp)
{
	char *argv1[] = {"cd",NULL};
	ft_execute(argv1, envp);

}*/