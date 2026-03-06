#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*str_tmp;
	unsigned char	c_tmp;

	i = 0;
	str_tmp = (unsigned char *) str;
	c_tmp = (unsigned char) c;
	while (i < n)
	{
		if (str_tmp[i] == c_tmp)
			return (str_tmp + i);
		i++;
	}
	return (0);
}
