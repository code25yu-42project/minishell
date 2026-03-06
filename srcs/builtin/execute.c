#include "execute.h"

t_builtin	find_builtin(int index)
{
	t_builtin	fp[7];

	fp[_ECHO] = ft_echo;
	fp[_CD] = ft_cd;
	fp[_PWD] = ft_pwd;
	fp[_EXPORT] = ft_export;
	fp[_UNSET] = ft_unset;
	fp[_ENV] = ft_env;
	fp[_EXIT] = ft_exit;
	return (fp[index]);
}
