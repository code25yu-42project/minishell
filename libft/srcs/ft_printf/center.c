#include "ft_printf.h"

int	ft_print_center(t_fmlst **fmlst, t_typelst *typelst, \
int p_space, int w_space)
{
	if ((*fmlst)->flag == 0)
	{
		if (ft_print_sign((*fmlst)->sign) == -1)
			return (-1);
		return (ft_print_va(*typelst, (*fmlst)->speci, (*fmlst)->va_len));
	}
	if ((*fmlst)->preci == 0 && (*fmlst)->flag & 64 \
	&& (*fmlst)->speci != STR && typelst->uint == 0)
		(*fmlst)->va_len = 0;
	if ((*fmlst)->preci > (*fmlst)->va_len)
		p_space = (*fmlst)->preci -(*fmlst)->va_len;
	if ((*fmlst)->width > p_space + (*fmlst)->va_len + (*fmlst)->sign_len)
		w_space = (*fmlst)->width - p_space \
		- (*fmlst)->va_len - (*fmlst)->sign_len;
	if (ft_sort_wp (fmlst, typelst, p_space, w_space) == -1)
		return (-1);
	if (p_space > 0 && (*fmlst)->speci != STR)
		(*fmlst)->va_len += p_space;
	if (w_space > 0)
		(*fmlst)->print_len += w_space;
	return (1);
}

int	ft_manage_center(t_fmlst **fmlst, t_typelst *typelst, const char *format)
{
	ft_manage_flag(fmlst, typelst);
	if ((*fmlst)->speci)
	{
		if (ft_manage_va_arg_s(fmlst, typelst) == -1)
			return (-1);
		if (ft_rcd_sign_pn(fmlst, typelst) == -1)
			return (-1);
		if (ft_rcd_sign_x(fmlst) == -1)
			return (-1);
	}
	if ((*fmlst)->flag != 0 && (*fmlst)->speci == 0 \
	&& typelst->llong == 0 && format[(*fmlst)->idx] == '\0')
		(*fmlst)->width = 0;
	return (1);
}

int	ft_format_rcd_center(t_fmlst **fmlst, t_typelst *typelst, \
va_list ap_format, const char *format)
{
	int		prg;
	char	format_chr;

	prg = 1;
	format_chr = format[(*fmlst)->idx];
	prg = ft_manage_percent(fmlst, typelst, format, format_chr);
	if (prg <= 0)
		return (prg);
	if (ft_rcd_flag(fmlst, ap_format, format, format_chr) == 1)
	{
		(*fmlst)->idx++;
		return (1);
	}
	return (2);
}

int	ft_rcd_center(t_fmlst **fmlst, t_typelst *typelst, \
va_list ap_format, const char *format)
{
	int	prg;

	prg = 1;
	while (prg == 1)
		prg = ft_format_rcd_center(fmlst, typelst, ap_format, format);
	if (prg <= 0)
		return (prg);
	ft_rcd_speci(fmlst, format[(*fmlst)->idx]);
	ft_rcd_va_arg(fmlst, typelst, ap_format);
	if (ft_manage_center(fmlst, typelst, format) == -1)
		return (-1);
	ft_rcd_va_len(fmlst, *typelst);
	return (1);
}

int	ft_print_va_center(t_fmlst **fmlst, va_list ap_format, const char *format)
{
	t_typelst	typelst;
	int			prg;

	prg = 1;
	prg = ft_manage_percent(fmlst, &typelst, format, format[(*fmlst)->idx]);
	if (prg <= 0)
	{
		ft_reset_lst_fmtype(fmlst, &typelst);
		return (prg);
	}
	prg = ft_rcd_center(fmlst, &typelst, ap_format, format);
	if (prg <= 0)
	{
		ft_reset_lst_fmtype(fmlst, &typelst);
		return (prg);
	}
	prg = ft_print_center(fmlst, &typelst, 0, 0);
	if (prg <= 0)
	{
		ft_reset_lst_fmtype(fmlst, &typelst);
		return (prg);
	}
	ft_reset_lst_fmtype(fmlst, &typelst);
	return (1);
}
