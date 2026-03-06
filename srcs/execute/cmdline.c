#include "execute.h"

char	*get_pathcmd(char **paths, char *cmd)
{
	int		index;
	char	*ret;

	index = 0;
	while (paths[index])
	{
		ret = ft_triplejoin(paths[index++], "/", cmd);
		if (!ret || !access(ret, X_OK))
			return (ret);
		free(ret);
	}
	return (ft_strdup(cmd));
}

char	*get_cmdpath(char **paths, char *cmd)
{
	char	*ret;

	if (is_builtin(cmd))
		ret = ft_strdup(cmd);
	else
		ret = get_pathcmd(paths, cmd);
	return (ret);
}

char	**get_cmdargs(char **cmds)
{
	t_deques	*deqs;
	size_t		index;
	char		**strs;

	deqs = create_deques();
	index = 0;
	if (!deqs)
		return (NULL);
	while (cmds[index])
	{
		if (set_parsing_deques(deqs, cmds[index]))
		{
			free_deques(&deqs);
			return (NULL);
		}
		index++;
	}
	strs = deqtostrs(deqs->head, NO);
	free_deques(&deqs);
	return (strs);
}
