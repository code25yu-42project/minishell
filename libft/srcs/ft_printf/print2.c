#include "ft_printf.h"

int	ft_putnbr_base(t_typelst typelst, char *base, char speci, int va_len)
{
	int	base_len;
	int	w_error;

	base_len = 0;
	w_error = 1;
	while (base && base[base_len])
		base_len++;
	if (speci == DEC || speci == INT)
		w_error = ft_print_ll(typelst.llong, va_len, base, base_len);
	else if (speci == UINT || speci == HEX_L || speci == HEX_U)
		w_error = ft_print_ui(typelst.uint, va_len, base, base_len);
	else if (speci == PTR)
		w_error = ft_print_ul(typelst.ulong, va_len, base, base_len);
	if (w_error == -1)
		return (-1);
	return (1);
}

int	ft_print_va(t_typelst typelst, char speci, int va_len)
{
	int	w_error;

	w_error = 0;
	if (speci == '\0')
		return (-1);
	else if (speci == CHAR)
		w_error = ft_print_char(typelst.chr);
	else if (speci == STR)
		w_error = ft_print_str(typelst.str, va_len);
	else if (speci == DEC || speci == INT)
		w_error = ft_putnbr_base(typelst, BASE_DEC, speci, va_len);
	else if (speci == UINT)
		w_error = ft_putnbr_base(typelst, BASE_DEC, speci, va_len);
	else if (speci == HEX_L || speci == ALTER_FORM_O)
		w_error = ft_putnbr_base(typelst, BASE_HEX_L, speci, va_len);
	else if (speci == HEX_U)
		w_error = ft_putnbr_base(typelst, BASE_HEX_U, speci, va_len);
	else if (speci == PTR)
		w_error = ft_putnbr_base(typelst, BASE_HEX_L, speci, va_len);
	if (w_error == -1)
		return (-1);
	return (1);
}

int	ft_print_sign(char sign)
{
	int	error_chk;

	if (sign == 0)
		return (0);
	error_chk = 0;
	if (sign & 1)
		error_chk = ft_print_char(LEFT_ORDER);
	else if (sign & 2)
		error_chk = ft_print_char(SPACE_PADDING);
	else if (sign & 4)
		error_chk = ft_print_char(SIGN_PLUS);
	else if (sign & 8)
		error_chk = ft_print_str(ZERO_X_L, 2);
	else if (sign & 16)
		error_chk = ft_print_str(ZERO_X_U, 2);
	return (error_chk);
}

int	ft_print_wp(int space, char chr)
{
	while (space-- > 0)
	{
		if (ft_print_char(chr) == -1)
			return (-1);
	}
	return (0);
}

int	ft_print_zero(t_fmlst **fmlst, t_typelst *typelst)
{
	if (!((*fmlst)->preci == 0 && (*fmlst)->flag & 64 \
	&& (*fmlst)->speci != STR && typelst->uint == 0))
		return (ft_print_va(*typelst, (*fmlst)->speci, (*fmlst)->va_len));
	return (1);
}
