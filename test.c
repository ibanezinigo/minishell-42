#include <stdio.h>
#include <stdlib.h>

#include <readline/readline.h>
#include <readline/history.h>

char	*readline(const char *prompt);

/*
Crear strcmp
*/

int main()
{
	char	*readl;

	readl = readline( "test> ");
	while (readl[0] != 'e')
	{
		add_history(readl);
		printf( "%s\n", readl);
		readl = readline( "test> ");
	}
	
    return 0;
}