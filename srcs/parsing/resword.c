#include "parsing.h"

int	ft_isresword(char chr)
{
	if (ft_isredirect(chr) || ft_ispipe(chr))
		return (TRUE);
	return (FALSE);
}

int	ft_isredirect(char chr)
{
	if (chr == LESS || chr == GREAT)
		return (TRUE);
	return (FALSE);
}

int	ft_ispipe(char chr)
{
	if (chr == PIPE)
		return (TRUE);
	return (FALSE);
}

int	ft_isquote(char chr)
{
	if (chr == SGL_QUOTE)
		return (T_SGL_QUOTE);
	else if (chr == DBL_QUOTE)
		return (T_DBL_QUOTE);
	return (FALSE);
}
