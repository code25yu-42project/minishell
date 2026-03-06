#include "ft_printf.h"

int	ft_print_sort_left(t_fmlst **fmlst, t_typelst *typelst, \
int p_space, int w_space)
{
	if (ft_print_sign((*fmlst)->sign) == -1)
		return (-1);
	if ((*fmlst)->speci != STR)
		if (ft_print_wp(p_space, ZERO_PADDING) == -1)
			return (-1);
	if (ft_print_zero(fmlst, typelst) == -1)
		return (-1);
	if (ft_print_wp(w_space, SPACE_PADDING) == -1)
		return (-1);
	return (1);
}

int	ft_print_sort_right(t_fmlst **fmlst, t_typelst *typelst, \
int p_space, int w_space)
{
	if ((*fmlst)->flag & 4)
	{
		if (ft_print_sign((*fmlst)->sign) == -1)
			return (-1);
		if (ft_print_wp(w_space, ZERO_PADDING) == -1)
			return (-1);
	}
	else
	{
		if (ft_print_wp(w_space, SPACE_PADDING) == -1)
			return (-1);
		if (ft_print_sign((*fmlst)->sign) == -1)
			return (-1);
	}
	if ((*fmlst)->speci != STR)
		if (ft_print_wp(p_space, ZERO_PADDING) == -1)
			return (-1);
	if (ft_print_zero(fmlst, typelst) == -1)
		return (-1);
	return (1);
}

int	ft_sort_wp(t_fmlst **fmlst, t_typelst *typelst, \
int p_space, int w_space)
{	
	if ((*fmlst)->flag & 2)
		return (ft_print_sort_left (fmlst, typelst, p_space, w_space));
	else
		return (ft_print_sort_right (fmlst, typelst, p_space, w_space));
	return (1);
}
