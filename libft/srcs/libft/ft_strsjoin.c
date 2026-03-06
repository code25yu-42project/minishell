#include "libft.h"

char	**ft_strsjoin(char **strs, char *str)
{
	char	**new_strs;
	int		i;

	i = 0;
	while (strs && strs[i])
		i++;
	new_strs = (char **)ft_calloc(i, sizeof(char *) * (i + 1));
	if (new_strs == NULL)
		return (NULL);
	i = 0;
	while (strs && strs[i])
	{	
		new_strs[i] = ft_strjoin(strs[i], str);
		if (new_strs[i] == NULL)
		{
			free_strs(&strs);
			return (NULL);
		}
		i++;
	}
	return (new_strs);
}
