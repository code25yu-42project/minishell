#include "minishell.h"

/* terminal */
void	get_terminal(t_shell *shell)
{
	tcgetattr(STDIN_FILENO, &shell->term);
}

void	reset_terminal(t_shell *shell)
{
	tcsetattr(STDIN_FILENO, TCSANOW, &shell->term);
}
