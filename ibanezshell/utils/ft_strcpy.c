#include "utils.h"

char	*ft_strcpy(char *src)
{
	char	*dest;
	int		i;

	if (!src)
		return (NULL);
	dest = malloc(sizeof(char) * (ft_strlen(src) + 1));
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}