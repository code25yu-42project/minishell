#include "libft.h"

int	ft_toupper(int c)
{
	size_t	n;

	if (!(c >= 'a' && c <= 'z'))
		return (c);
	n = 'a' - 'A';
	return (c - n);
}
