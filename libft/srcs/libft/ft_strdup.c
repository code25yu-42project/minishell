#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	size;
	size_t	i;
	char	*ptr;

	size = 0;
	i = 0;
	while (*(s1 + size))
		size++;
	ptr = (char *)malloc(sizeof(char) * size + 1);
	if (ptr == NULL)
		return (0);
	while (i < size)
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
