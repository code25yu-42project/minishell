#include "ft_printf.h"

void	ft_va_len(t_typelst typelst, char speci, long long radix, int *digit)
{
	(*digit)++;
	if (speci == DEC || speci == INT)
	{
		while (typelst.llong > (long long)(radix - 1))
		{
			(*digit)++;
			typelst.llong /= (long long)radix;
		}
	}
	else if (speci == PTR)
	{
		while (typelst.ulong > (unsigned long)(radix - 1))
		{
			(*digit)++;
			typelst.ulong /= (unsigned long)radix;
		}
	}
	else if (speci == UINT || speci == HEX_L || speci == HEX_U)
	{	
		while (typelst.uint > (unsigned int)(radix - 1))
		{
			(*digit)++;
			typelst.uint /= (unsigned int)radix;
		}
	}
}

void	ft_rcd_va_len(t_fmlst **fmlst, t_typelst typelst)
{
	if ((*fmlst)->speci == CHAR)
		(*fmlst)->va_len++;
	else if ((*fmlst)->speci == STR && typelst.str)
		(*fmlst)->va_len = ft_strlen(typelst.str);
	else if ((*fmlst)->speci == DEC \
	|| (*fmlst)->speci == INT || (*fmlst)->speci == UINT)
		ft_va_len(typelst, (*fmlst)->speci, 10, &((*fmlst)->va_len));
	else if ((*fmlst)->speci == HEX_L || (*fmlst)->speci == HEX_U \
	|| (*fmlst)->speci == PTR)
		ft_va_len(typelst, (*fmlst)->speci, 16, &((*fmlst)->va_len));
}
