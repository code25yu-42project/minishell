#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!(needle[i]))
		return ((char *) haystack);
	while (haystack[i] && i < len)
	{
		j = 0;
		while (haystack[i] && i < len && haystack[i] == needle[j])
		{
			i++;
			j++;
			if (!(needle[j]))
				return ((char *)haystack + i - j);
		}
		if (j > 0)
			i -= j;
		i++;
	}
	return (0);
}
