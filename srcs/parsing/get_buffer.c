#include "parsing.h"

static int	replace_pipebuffer(char **dstbuffer);
static int	has_balanced_quotes(char *buffer);

int	get_validbuffer(char *buffer, char **validbuffer)
{
	int		code;

	*validbuffer = ft_strdup(buffer);
	if (!*validbuffer)
		return (EXTRA_ERROR);
	if (!has_balanced_quotes(*validbuffer))
	{
		g_status = SYNTAX_ERROR;
		return (handle_error(NULL, NULL, SYN_TERM));
	}
	while (1)
	{
		if (handle_empty_pipe(*validbuffer) == SYNTAX_ERROR \
		|| handle_empty_redirect(*validbuffer) == SYNTAX_ERROR)
		{
			g_status = SYNTAX_ERROR;
			return (SYNTAX_ERROR);
		}
		else if (ft_ispipeopen(*validbuffer) == TRUE)
		{
			code = replace_pipebuffer(validbuffer);
			if (code == SYNTAX_ERROR)
				g_status = SYNTAX_ERROR;
			if (code != EXIT_SUCCESS)
				return (code);
		}
		else
			break ;
	}
	return (EXIT_SUCCESS);
}

static int	replace_pipebuffer(char **dstbuffer)
{
	char	*srcbuffer;

	if (set_next_cmd(&srcbuffer))
	{
		free(*dstbuffer);
		free(srcbuffer);
		*dstbuffer = NULL;
		return (handle_error(NULL, NULL, SYN_TERM));
	}
	else
		*dstbuffer = strjoin_free(*dstbuffer, srcbuffer);
	if (!*dstbuffer)
		return (EXTRA_ERROR);
	return (EXIT_SUCCESS);
}

static int	has_balanced_quotes(char *buffer)
{
	int	is_sgl_open;
	int	is_dbl_open;

	is_sgl_open = FALSE;
	is_dbl_open = FALSE;
	while (buffer && *buffer)
	{
		if (*buffer == SGL_QUOTE && !is_dbl_open)
			is_sgl_open = !is_sgl_open;
		else if (*buffer == DBL_QUOTE && !is_sgl_open)
			is_dbl_open = !is_dbl_open;
		buffer++;
	}
	return (!is_sgl_open && !is_dbl_open);
}
