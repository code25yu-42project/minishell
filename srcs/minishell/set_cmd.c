#include "minishell.h"

int	set_cmd(t_shell *shell)
{
	size_t	index;
	int		status;

	index = 0;
	if (set_env_paths(&shell->data))
		return (EXTRA_ERROR);
	while (index < shell->p_size)
	{
		if (set_args(&shell->p[index], shell->data))
			return (EXTRA_ERROR);
		status = set_redirect(&shell->p[index], shell->data.envps);
		if (status)
			return (status);
		index++;
	}
	return (EXIT_SUCCESS);
}
