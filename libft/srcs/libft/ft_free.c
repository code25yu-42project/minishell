#include "libft.h"

void	free_str(char **str)
{
	free(*str);
	*str = NULL;
}

void	free_strs(char ***strs)
{
	int	i;

	i = 0;
	while (*strs && (*strs)[i])
	{
		free((*strs)[i]);
		(*strs)[i] = 0;
		i++;
	}
	if (*strs != NULL)
	{
		free(*strs);
		*strs = NULL;
	}
}
