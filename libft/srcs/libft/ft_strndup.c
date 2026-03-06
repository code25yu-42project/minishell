#include "libft.h"

char	*ft_strndup(const char *str, size_t len)
{
	char	*new;

	new = (char *)malloc(len + 1);
	if (new == NULL)
		return (NULL);
	ft_strlcpy(new, str, len);
	return (new);
}
