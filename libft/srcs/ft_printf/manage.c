#include "ft_printf.h"

int	ft_rcd_sign_x(t_fmlst **fmlst)
{
	if ((*fmlst)->speci == PTR)
		(*fmlst)->sign += 8;
	else if ((*fmlst)->speci == HEX_L && ((*fmlst)->flag & 32))
		(*fmlst)->sign += 8;
	else if ((*fmlst)->speci == HEX_U && ((*fmlst)->flag & 32))
		(*fmlst)->sign += 16;
	else
		return (0);
	(*fmlst)->sign_len += 2;
	return (1);
}

int	ft_rcd_sign_pn(t_fmlst **fmlst, t_typelst *typelst)
{
	if ((*fmlst)->speci == DEC || (*fmlst)->speci == INT)
	{
		if (typelst->llong < 0)
		{
			typelst->llong *= -1;
			(*fmlst)->sign += 1;
		}
		else if ((*fmlst)->flag & 8)
			(*fmlst)->sign += 2;
		else if ((*fmlst)->flag & 16)
			(*fmlst)->sign += 4;
		else
			return (0);
		(*fmlst)->sign_len++;
	}
	return (1);
}

int	ft_manage_va_arg_s(t_fmlst **fmlst, t_typelst *typelst)
{
	int	strlen;

	if ((*fmlst)->speci != STR)
		return (0);
	if (typelst->str == NULL)
		typelst->str = "(null)";
	if (typelst->str != NULL)
		strlen = ft_strlen(typelst->str);
	if ((*fmlst)->flag & 64 && (*fmlst)->preci < strlen)
	{
		typelst->str = ft_substr(typelst->str, 0, (*fmlst)->preci);
		if (typelst->str == NULL)
			return (-1);
		(*fmlst)->malloc++;
	}
	if ((*fmlst)->flag & 128 && (*fmlst)->preci > strlen)
		(*fmlst)->preci = strlen;
	return (1);
}

void	ft_manage_flag(t_fmlst **fmlst, t_typelst *typelst)
{
	if ((*fmlst)->flag & 16 && (*fmlst)->flag & 8)
		(*fmlst)->flag -= 8;
	if ((*fmlst)->flag & 2 && (*fmlst)->flag & 4)
		(*fmlst)->flag -= 4;
	if ((*fmlst)->flag & 64 && (*fmlst)->flag & 4)
		(*fmlst)->flag -= 4;
	if ((*fmlst)->flag & 32)
		if (((*fmlst)->speci != HEX_L && (*fmlst)->speci != HEX_U) \
			|| (typelst)->uint == 0)
			(*fmlst)->flag -= 32;
}

int	ft_manage_percent(t_fmlst **fmlst, t_typelst *typelst, \
const char *format, char format_chr)
{
	while (format_chr == PERCENT)
	{	
		if (!((*fmlst)->flag & 1))
		{
			(*fmlst)->flag += 1;
			(*fmlst)->idx++;
			format_chr = format[(*fmlst)->idx];
		}
		else if ((*fmlst)->flag & 1)
		{
			typelst->chr = format_chr;
			(*fmlst)->speci = CHAR;
			(*fmlst)->idx++;
			ft_rcd_va_len(fmlst, *typelst);
			if (ft_print_center(fmlst, typelst, 0, 0) == -1)
				return (-1);
			ft_reset_lst_fmtype(fmlst, typelst);
			return (0);
		}
	}
	if ((*fmlst)->flag & 1 && format_chr != '\0')
		return (1);
	else
		return (0);
}
