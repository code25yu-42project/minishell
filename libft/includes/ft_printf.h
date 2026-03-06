#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# ifndef PERCENT
#  define PERCENT '%'
#  define LEFT_ORDER '-'
#  define ZERO_PADDING '0'
#  define SPACE_PADDING ' '
#  define SIGN_PLUS '+'
#  define ALTER_FORM '#'
#  define ALTER_FORM_O 'o'
#  define PRECI '.'
#  define ASTERISK '*'

#  define ZERO_X_L "0x"
#  define ZERO_X_U "0X"

#  define CHAR 'c'
#  define STR 's'
#  define DEC 'd'
#  define INT 'i'
#  define UINT 'u'
#  define HEX_L 'x'
#  define HEX_U 'X'
#  define PTR 'p'

#  define BASE_DEC "0123456789"
#  define BASE_HEX_U "0123456789ABCDEF"
#  define BASE_HEX_L "0123456789abcdef"
# endif

typedef union u_typelst
{
	long long		llong;
	unsigned int	uint;
	unsigned long	ulong;
	char			chr;
	char			*str;
}t_typelst;

typedef struct s_fmlst
{
	unsigned char	flag;
	int				width;
	int				preci;
	char			speci;

	int				va_len;
	int				sign_len;
	int				print_len;

	int				idx;
	char			malloc;
	char			sign;
}t_fmlst;

int		ft_isalpha(int c);
int		ft_isdigit(int c);
size_t	ft_strlen(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_memset(void *ptr, int c, size_t len);

int		ft_print_char(char chr);
int		ft_print_str(char *str, int va_len);
int		ft_print_ll(long long num, long long va_len, \
char *base, long long base_len);
int		ft_print_ul(unsigned long num, unsigned long va_len, \
char *base, unsigned long base_len);
int		ft_print_ui(unsigned int num, unsigned int va_len, \
char *base, unsigned int base_len);

int		ft_putnbr_base(t_typelst typelst, char *base, char speci, int va_len);
int		ft_print_va(t_typelst typelst, char speci, int va_len);
int		ft_print_sign(char sign);
int		ft_print_wp(int space, char chr);
int		ft_print_zero(t_fmlst **fmlst, t_typelst *typelst);

int		ft_print_sort_left(t_fmlst **fmlst, t_typelst *typelst, \
int p_space, int w_space);
int		ft_print_sort_right(t_fmlst **fmlst, t_typelst *typelst, \
int p_space, int w_space);
int		ft_sort_wp(t_fmlst **fmlst, t_typelst *typelst, \
int p_space, int w_space);

int		ft_new_fmlst(t_fmlst **fmlst);
void	ft_reset_lst_fmtype(t_fmlst **fmlst, t_typelst *typelst);
void	ft_freeturn_fmlst(t_fmlst **fmlst, int *pf_return);

int		ft_isspeci(char format_chr);
int		ft_isflag(char format_chr);

void	ft_va_len(t_typelst typelst, char speci, long long radix, int *digit);
void	ft_rcd_va_len(t_fmlst **fmlst, t_typelst typelst);

int		ft_rcd_sign_x(t_fmlst **fmlst);
int		ft_rcd_sign_pn(t_fmlst **fmlst, t_typelst *typelst);
int		ft_manage_va_arg_s(t_fmlst **fmlst, t_typelst *typelst);
void	ft_manage_flag(t_fmlst **fmlst, t_typelst *typelst);
int		ft_manage_percent(t_fmlst **fmlst, t_typelst *typelst, \
const char *format, char format_chr);

void	ft_rcd_va_arg(t_fmlst **fmlst, t_typelst *typelst, va_list ap_format);
int		ft_rcd_speci(t_fmlst **fmlst, char format_chr);
void	ft_preci_rcd(t_fmlst **fmlst, const char *format);
void	ft_width_rcd(t_fmlst **fmlst, \
va_list ap_format, const char *format, char format_chr);
int		ft_rcd_flag(t_fmlst **fmlst, \
va_list ap_format, const char *format, char format_chr);

int		ft_print_center(t_fmlst **fmlst, t_typelst *typelst, \
int p_space, int w_space);
int		ft_manage_center(t_fmlst **fmlst, t_typelst *typelst, \
const char *format);
int		ft_rcd_flag_center(t_fmlst **fmlst, t_typelst *typelst, \
va_list ap_format, const char *format);
int		ft_rcd_center(t_fmlst **fmlst, t_typelst *typelst, \
va_list ap_format, const char *format);
int		ft_print_va_center(t_fmlst **fmlst, \
va_list ap_format, const char *format);

int		ft_printf(const char *format, ...);

#endif
