
#include "utils.h"

//USADO
void	ft_strcut_toend(char *str, int from)
{
	int	i;

	i = 0;
	while (str[from + i])
	{
		str[i] = str[from + i];
		i++;
	}
	str[i] = str[from + i];
}
