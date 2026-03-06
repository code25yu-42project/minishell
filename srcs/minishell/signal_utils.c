#include "minishell.h"

void	handler_init(int signo)
{
	if (signo == SIGINT)
	{
		replace_line(TRUE);
		g_status = EXIT_FAILURE;
	}
	if (signo == SIGTERM)
	{
		ft_putstr_fd("\033[1A", STDERR_FILENO);
		ft_putstr_fd("\033[12C", STDERR_FILENO);
		ft_putstr_fd("exit\n", STDERR_FILENO);
	}
}

void	handler_sub(int signo)
{
	g_status = signo + SIGEXIT;
	if (signo == SIGINT)
	{
		rl_on_new_line();
		rl_replace_line("", 0);
	}
}

void	handler_child(int status)
{
	if (WIFSIGNALED(status) == 1)
	{
		if (status == 2)
			ft_putstr_fd("\n", STDERR_FILENO);
		else if (status == 3)
			ft_putstr_fd("Quit: 3\n", STDERR_FILENO);
	}
}

void	replace_line(int redisplayon)
{
	ft_putchar_fd('\n', STDOUT_FILENO);
	rl_on_new_line();
	rl_replace_line("", 0);
	if (redisplayon == TRUE)
		rl_redisplay();
}
