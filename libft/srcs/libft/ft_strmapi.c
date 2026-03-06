#include "libft.h"

char	*ft_strmapi(char const *str, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*res;

	i = 0;
	res = (char *)malloc(sizeof (char) * (ft_strlen(str) + 1));
	if (res == NULL)
		return (0);
	while (str[i])
	{
		res[i] = f(i, str[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}
