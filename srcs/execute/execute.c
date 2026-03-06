#include "execute.h"

int	fork_process(t_process *p)
{
	p->pid = fork();
	if (p->pid == -1)
		return (EXTRA_ERROR);
	return (EXIT_SUCCESS);
}

int	set_cmdargs(t_process *p, char **argvs)
{
	p->exec.args = get_cmdargs(argvs);
	if (!p->exec.args)
		return (EXTRA_ERROR);
	return (EXIT_SUCCESS);
}

int	set_cmdpath(t_process *p, char **paths, char *cmd)
{
	p->exec.path = get_cmdpath(paths, cmd);
	if (!p->exec.path)
		return (EXTRA_ERROR);
	return (EXIT_SUCCESS);
}
