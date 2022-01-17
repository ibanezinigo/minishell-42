#include "utils.h"

char	*ft_append_tostr(char *str, char *str2)
{
	char	*tmp;

	tmp = ft_strcat(str, str2);
	free(str);
	return (tmp);
}
