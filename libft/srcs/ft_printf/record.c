#include "ft_printf.h"

void	ft_rcd_va_arg(t_fmlst **fmlst, t_typelst *typelst, va_list ap_format)
{
	if ((*fmlst)->speci == CHAR)
		typelst->chr = va_arg(ap_format, int);
	else if ((*fmlst)->speci == STR)
		typelst->str = va_arg(ap_format, char *);
	else if ((*fmlst)->speci == DEC || (*fmlst)->speci == INT)
		typelst->llong = va_arg(ap_format, int);
	else if ((*fmlst)->speci == PTR)
		typelst->ulong = va_arg(ap_format, unsigned long);
	else if ((*fmlst)->speci == UINT \
	|| (*fmlst)->speci == HEX_L || (*fmlst)->speci == HEX_U)
		typelst->uint = va_arg(ap_format, unsigned int);
}

int	ft_rcd_speci(t_fmlst **fmlst, char format_chr)
{
	if (!((*fmlst)->flag & 1))
		return (0);
	if (ft_isspeci(format_chr) == 1)
	{
		(*fmlst)->speci = format_chr;
		(*fmlst)->idx++;
	}
	return (1);
}

void	ft_preci_rcd(t_fmlst **fmlst, const char *format)
{
	char	format_chr;

	(*fmlst)->flag += 64;
	(*fmlst)->idx++;
	while (format && format[(*fmlst)->idx])
	{
		format_chr = format[(*fmlst)->idx];
		if (format_chr && ft_isdigit(format_chr) == 0)
		{
			(*fmlst)->idx--;
			return ;
		}
		(*fmlst)->preci = (10 * ((*fmlst)->preci)) + (format_chr - '0');
		(*fmlst)->idx++;
	}
}

void	ft_width_rcd(t_fmlst **fmlst, va_list ap_format, \
const char *format, char format_chr)
{
	(*fmlst)->flag += 128;
	if (format_chr == ASTERISK)
	{
		(*fmlst)->width = va_arg(ap_format, int);
		(*fmlst)->idx++;
	}
	while (format && format[(*fmlst)->idx])
	{
		format_chr = format[(*fmlst)->idx];
		if (format_chr && ft_isdigit(format_chr) == 0)
		{
			(*fmlst)->idx--;
			return ;
		}
		(*fmlst)->width = (10 * ((*fmlst)->width)) + (format_chr - '0');
		(*fmlst)->idx++;
	}
}

int	ft_rcd_flag(t_fmlst **fmlst, \
va_list ap_format, const char *format, char format_chr)
{
	if (format_chr == LEFT_ORDER && !((*fmlst)->flag & 2))
		(*fmlst)->flag += 2;
	else if (format_chr == ZERO_PADDING && !((*fmlst)->flag & 4))
		(*fmlst)->flag += 4;
	else if (format_chr == SPACE_PADDING && !((*fmlst)->flag & 8))
		(*fmlst)->flag += 8;
	else if (format_chr == SIGN_PLUS && !((*fmlst)->flag & 16))
		(*fmlst)->flag += 16;
	else if (format_chr == ALTER_FORM && !((*fmlst)->flag & 32))
		(*fmlst)->flag += 32;
	else if (format_chr == PRECI)
		ft_preci_rcd(fmlst, format);
	else if (ft_isdigit(format_chr) == 1 || format_chr == ASTERISK)
		ft_width_rcd(fmlst, ap_format, format, format_chr);
	else if (ft_isflag(format_chr) == 1)
		return (1);
	else
		return (0);
	return (1);
}
