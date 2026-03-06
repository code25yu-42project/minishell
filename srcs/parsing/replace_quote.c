#include "parsing.h"

char	*replace_quote(char *str)
{
	char	*headstr;
	char	*dst;
	char	*src;
	int		len;

	headstr = str;
	dst = ft_calloc(1, sizeof(char));
	while (*str)
	{
		len = wordlen(str);
		if (ft_isquote(*str) && is_closed_quotation(str))
			src = ft_substr(str, 1, len - 2);
		else
			src = ft_substr(str, 0, len);
		dst = strjoin_free(dst, src);
		str += len;
	}
	free (headstr);
	return (dst);
}
