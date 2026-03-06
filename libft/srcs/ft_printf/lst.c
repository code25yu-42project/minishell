#include "ft_printf.h"

int	ft_new_fmlst(t_fmlst **fmlst)
{
	*fmlst = (t_fmlst *)malloc(sizeof(t_fmlst));
	if (*fmlst == NULL)
		return (-1);
	ft_memset(*fmlst, 0, sizeof(t_fmlst));
	return (1);
}

void	ft_reset_lst_fmtype(t_fmlst **fmlst, t_typelst *typelst)
{
	int	print_len;
	int	fm_idx;

	(*fmlst)->print_len += ((*fmlst)->va_len + (*fmlst)->sign_len);
	if ((*fmlst)->malloc > 0)
	{
		free(typelst->str);
		typelst->str = NULL;
	}
	print_len = (*fmlst)->print_len;
	fm_idx = (*fmlst)->idx;
	ft_memset(*fmlst, 0, sizeof(t_fmlst));
	ft_memset(typelst, 0, sizeof(t_typelst));
	(*fmlst)->print_len = print_len;
	(*fmlst)->idx = fm_idx;
}

void	ft_freeturn_fmlst(t_fmlst **fmlst, int *pf_return)
{	
	if (*pf_return != -1)
		(*pf_return) = (*fmlst)->print_len;
	free((*fmlst));
	(*fmlst) = NULL;
}
