#include "ft_printf.h"

int	ft_print_char(char chr)
{
	return (write(1, &chr, 1));
}

int	ft_print_str(char *str, int va_len)
{
	return (write(1, str, va_len));
}

int	ft_print_ll(long long num, long long va_len, \
char *base, long long base_len)
{
	long long	digit_base;
	long long	digit_idx;

	digit_base = 1;
	digit_idx = 0;
	while (va_len-- > 1)
		digit_base *= base_len;
	while (digit_base > 0)
	{
		if (digit_base > 0)
			digit_idx = num / digit_base;
		else
			digit_idx = num % digit_base;
		if (ft_print_char(base[digit_idx]) == -1)
			return (-1);
		if (digit_base > 0)
			num %= digit_base;
		digit_base /= base_len;
	}
	return (1);
}

int	ft_print_ul(unsigned long num, unsigned long va_len, \
char *base, unsigned long base_len)
{
	unsigned long	digit_base;
	unsigned long	digit_idx;

	digit_base = 1;
	digit_idx = 0;
	while (va_len-- > 1)
		digit_base *= base_len;
	while (digit_base > 0)
	{
		if (digit_base > 0)
			digit_idx = num / digit_base;
		else
			digit_idx = num % digit_base;
		if (ft_print_char(base[digit_idx]) == -1)
			return (-1);
		if (digit_base > 0)
			num %= digit_base;
		digit_base /= base_len;
	}
	return (1);
}

int	ft_print_ui(unsigned int num, unsigned int va_len, \
char *base, unsigned int base_len)
{
	unsigned int	digit_base;
	unsigned int	digit_idx;

	digit_base = 1;
	digit_idx = 0;
	while (va_len-- > 1)
		digit_base *= base_len;
	while (digit_base > 0)
	{
		if (digit_base > 0)
			digit_idx = num / digit_base;
		else
			digit_idx = num % digit_base;
		if (ft_print_char(base[digit_idx]) == -1)
			return (-1);
		if (digit_base > 0)
			num %= digit_base;
		digit_base /= base_len;
	}
	return (1);
}
