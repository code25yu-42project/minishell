#include "libft.h"

int	ft_tolower(int c)
{
	size_t	n;

	if (!(c >= 'A' && c <= 'Z'))
		return (c);
	n = 'a' - 'A';
	return (c + n);
}
