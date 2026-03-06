#include "ft_printf.h"

int	ft_isspeci(char format_chr)
{
	if (format_chr == STR || format_chr == CHAR \
	|| format_chr == DEC || format_chr == INT || format_chr == UINT \
	|| format_chr == HEX_L || format_chr == HEX_U || format_chr == PTR)
		return (1);
	return (0);
}

int	ft_isflag(char format_chr)
{
	if (format_chr == PERCENT \
	|| format_chr == LEFT_ORDER || format_chr == ZERO_PADDING \
	|| format_chr == SPACE_PADDING || format_chr == SIGN_PLUS \
	|| format_chr == ALTER_FORM || format_chr == PRECI \
	|| format_chr == ASTERISK)
		return (1);
	return (0);
}
