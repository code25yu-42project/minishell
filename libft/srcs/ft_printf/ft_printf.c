#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	t_fmlst		*fmlst;
	va_list		ap_format;
	int			pf_return;

	pf_return = 0;
	va_start(ap_format, format);
	if (ft_new_fmlst(&fmlst) == -1)
		return (-1);
	while (format && format[fmlst->idx])
	{	
		if (format[fmlst->idx] == PERCENT)
			pf_return = ft_print_va_center(&fmlst, ap_format, format);
		else
		{
			pf_return = ft_print_char(format[fmlst->idx++]);
			fmlst->print_len++;
		}
		if (pf_return == -1)
			break ;
	}
	va_end(ap_format);
	ft_freeturn_fmlst(&fmlst, &pf_return);
	return (pf_return);
}
