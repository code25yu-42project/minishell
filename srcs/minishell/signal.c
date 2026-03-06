#include "minishell.h"

int	set_signal(void (*handler)(int), int signo)
{
	t_sigaction	action;

	action.sa_handler = handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = 0;
	if (sigaction(signo, &action, NULL) == -1)
		return (EXTRA_ERROR);
	return (EXIT_SUCCESS);
}

int	set_signal_init(void (*handler)(int))
{
	int	status;

	terminal_printoff();
	status = set_signal(handler, SIGINT);
	if (!status)
		status = set_signal(handler, SIGTERM);
	if (!status)
		status = set_signal(SIG_IGN, SIGQUIT);
	return (status);
}

int	set_signal_sub(void (*handler)(int))
{
	int	status;

	terminal_printon();
	status = set_signal(handler, SIGINT);
	if (!status)
		status = set_signal(handler, SIGQUIT);
	return (status);
}
