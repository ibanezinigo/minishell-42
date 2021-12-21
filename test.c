#include <stdio.h>
#include <stdlib.h>

#include <readline/readline.h>
#include <readline/history.h>

char	*readline(const char *prompt);

int main()
{
    printf( "%s\n", readline( "test> " ) );
    return 0;
}