#include "parsing.h"

char	*replace_word(t_deques *envps, char *str)
{
	str = replace_value(envps, str);
	if (!str)
		return (NULL);
	str = replace_quote(str);
	if (!str)
		return (NULL);
	return (str);
}
