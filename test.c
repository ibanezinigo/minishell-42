#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>

void ft_close_pipes(int *pipes, int n)
{
    int i;

    i = 0;
    while (i < n - 1)
    {
        close(pipes[i * 2]);
        close(pipes[i * 2 + 1]);
        i++;
    }
}

int main(int argc, char **argv)
{
    int status;
    int i;
    int n;

    n = 4;
    // arguments for commands; your parser would be responsible for
    // setting up arrays like these

    char *cat_args[] = {"ls", NULL};
    char *grep_args[] = {"wc", NULL};
    char *cut_args[] = {"cat", NULL};
    char *cut_args2[] = {"grep","2",NULL};
    char **commands[] = {cat_args, grep_args, cut_args, cut_args2};

    // make 2 pipes (cat to grep and grep to cut); each has 2 fds

    int *pipes;
    pipes = malloc(sizeof(int) * (n + 1));

    i = 0;
    while (i < n - 1)
    {
        pipe(&pipes[i * 2]); // sets up 1st pipe
        i = i + 1;
    }
    i = 0;
    while (i < n)
    {
        if (fork() == 0)
        {
            if (i == 0)
            {
                // replace cat's stdout with write part of 1st pipe
                dup2(pipes[1], 1);
                // close all pipes (very important!); end we're using was safely copied
                ft_close_pipes(pipes, n);
                execvp(*commands[i], commands[i]);
            }
            else if (i < (n - 1))
            {
                // replace grep's stdin with read end of 1st pipe
                dup2(pipes[(i - 1) * 2], 0);
                // replace grep's stdout with write end of 2nd pipe
                dup2(pipes[(i * 2) + 1], 1);
                // close all ends of pipes
                ft_close_pipes(pipes, n);
                execvp(*commands[i], commands[i]);
            }
            else if (i == (n - 1))
            {
                // replace cut's stdin with input read of 2nd pipe
                dup2(pipes[(i - 1) * 2], 0);
                // close all ends of pipes
                ft_close_pipes(pipes, n);
                execvp(*commands[i], commands[i]);
            }
        }
        i++;
    }
    ft_close_pipes(pipes, n);

    for (i = 0; i < n; i++)
        wait(&status);
}
