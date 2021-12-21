#include <stdio.h>
#include <stdlib.h>

#include <readline/readline.h>
#include <readline/history.h>

char	*readline(const char *prompt);

/*
Crear strcmp
*/

int	ft_strlen(char *str)
{
	int	size;

	size = 0;
	while (str[size])
		size = size + 1;
	return (size);
}

char	*ft_strcpy(char *src)
{
	char	*dest;
	int		i;

	dest = malloc(sizeof(char) * (ft_strlen(src) + 1));
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

char	*ft_get_next_token(char *src)
{
	return (NULL)
}

char **ft_lexer(char *readl)
{
	char	*buff;
	char	**result;
	int		i;

	buff = ft_strcpy(readl);

	free(buff);
	return (NULL);
}

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