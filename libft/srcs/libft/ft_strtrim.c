#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trmstr;
	size_t	begin;
	size_t	end;
	size_t	i;

	begin = 0;
	end = ft_strlen(s1);
	i = 0;
	while (s1[begin] && ft_strchr(set, s1[begin]))
		begin++;
	while (end && ft_strchr(set, s1[end - 1]) && begin + 1 < end)
		end--;
	trmstr = (char *)malloc(sizeof (char) * (end - begin + 1));
	if (trmstr == NULL)
		return (0);
	if (s1 && set)
	{
		while (s1[begin] && begin <= end - 1)
			trmstr[i++] = s1[begin++];
	}
	trmstr[i] = '\0';
	return (trmstr);
}
