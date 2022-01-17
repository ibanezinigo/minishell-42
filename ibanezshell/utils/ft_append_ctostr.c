#include "utils.h"

char    *ft_append_ctostr(char *str, char c)
{
	char	*newstr;
	int		i;

	if (str == NULL)
	{
		str = malloc(2);
		str[0] = c;
		str[1] = '\0';
		return (str);
	}
	newstr = malloc(ft_strlen(str) + 2);
	i = 0;
	while (str[i])
	{
		newstr[i] = str[i];
		i++;
	}
	newstr[i] = c;
	newstr[i + 1] = '\0';
	free(str);
	return (newstr);
}
