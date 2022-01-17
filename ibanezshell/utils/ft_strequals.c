#include "utils.h"

//USADO
int	ft_strequals(char *str1, char *str2)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	if (ft_strlen(str1) != ft_strlen(str2))
		return (0);
	while (str1[i])
	{
		if (str1[i] != str2[i])
			return (0);
		i++;
	}
	return (1);
}