NAME = minishell

CC = cc
CFLAGS = -Wall -Wextra -Werror
DEPFLAGS = -MMD -MP

READLINE_PREFIX ?= $(shell brew --prefix readline 2>/dev/null)

ifeq ($(strip $(READLINE_PREFIX)),)
ifneq ($(wildcard /opt/homebrew/opt/readline),)
READLINE_PREFIX = /opt/homebrew/opt/readline
else ifneq ($(wildcard /usr/local/opt/readline),)
READLINE_PREFIX = /usr/local/opt/readline
endif
endif

READLINE_INC     = -I$(READLINE_PREFIX)/include
READLINE_LIB_DIR = -L$(READLINE_PREFIX)/lib

# Directories containing header files (add paths if needed)
MINISHELL_INC_DIRS = ./includes ./libft/includes

# Add the -I prefix to each include directory
MINISHELL_INC = $(addprefix -I, $(MINISHELL_INC_DIRS))

MINISHELL_LIB_DIR = -Llibft

CPPFLAGS = ${READLINE_INC} ${MINISHELL_INC} ${DEPFLAGS}
LDFLAGS = ${READLINE_LIB_DIR} ${MINISHELL_LIB_DIR}
LDLIBS = -lreadline -lft

SHELLDIR = ./srcs/minishell/
BUILTINDIR = ./srcs/builtin/
EXECDIR = ./srcs/execute/
PARSEDIR = ./srcs/parsing/
UTILSDIR = ./srcs/utils/
DEQDIR = ./srcs/deque/
TERMDIR = ./srcs/terminal/
ERRDIR = ./srcs/err/

# Collect deque-related sources in a separate variable
DEQ_SRCS = \
	$(DEQDIR)utils.c \
	$(DEQDIR)deque.c \
	$(DEQDIR)free.c \
	$(DEQDIR)pop.c \
	$(DEQDIR)push.c \
	$(DEQDIR)api.c \
	$(DEQDIR)map.c

BUILTIN_SRCS = \
	$(BUILTINDIR)utils.c \
	$(BUILTINDIR)cd.c \
	$(BUILTINDIR)cd_utils.c \
	$(BUILTINDIR)echo.c \
	$(BUILTINDIR)env.c \
	$(BUILTINDIR)execute.c \
	$(BUILTINDIR)exit.c \
	$(BUILTINDIR)export.c \
	$(BUILTINDIR)export_utils.c \
	$(BUILTINDIR)pwd.c \
	$(BUILTINDIR)unset.c \
	$(BUILTINDIR)builtin.c

EXEC_SRCS = \
	$(EXECDIR)heredoc.c \
	$(EXECDIR)heredoc_signal.c \
	$(EXECDIR)execute.c \
	$(EXECDIR)cmdline.c \
	$(EXECDIR)cmdline_utils.c \
	$(EXECDIR)redirect.c \
	$(EXECDIR)redirect_utils.c \
	$(EXECDIR)free.c \
	$(EXECDIR)next_cmd.c

PARSE_SRCS = \
	$(PARSEDIR)parsing.c \
	$(PARSEDIR)get_buffer.c \
	$(PARSEDIR)pipe.c \
	$(PARSEDIR)redirect.c \
	$(PARSEDIR)argv.c \
	$(PARSEDIR)wordend.c \
	$(PARSEDIR)wordlen.c \
	$(PARSEDIR)tokenizer.c \
	$(PARSEDIR)token_utils.c \
	$(PARSEDIR)token_lst.c \
	$(PARSEDIR)parser.c \
	$(PARSEDIR)replace_word.c \
	$(PARSEDIR)replace_quote.c \
	$(PARSEDIR)replace_value.c \
	$(PARSEDIR)replace_value_utils.c \
	$(PARSEDIR)resword.c \
	$(PARSEDIR)utils.c

SHELL_SRCS = \
	$(SHELLDIR)main.c \
	$(SHELLDIR)execute.c \
	$(SHELLDIR)free.c \
	$(SHELLDIR)setting.c \
	$(SHELLDIR)process.c \
	$(SHELLDIR)process_utils.c \
	$(SHELLDIR)set_cmd.c \
	$(SHELLDIR)validation.c \
	$(SHELLDIR)terminal.c \
	$(SHELLDIR)signal.c \
	$(SHELLDIR)signal_utils.c

UTILS_SRCS = $(UTILSDIR)utils.c

ERR_SRCS = $(ERRDIR)print.c

TERM_SRCS = $(TERMDIR)term.c

SRCS = $(DEQ_SRCS) $(BUILTIN_SRCS) $(EXEC_SRCS) $(PARSE_SRCS) $(SHELL_SRCS) $(UTILS_SRCS) $(TERM_SRCS) $(ERR_SRCS)

OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)

all : $(NAME)

-include $(DEPS)

$(NAME) : $(OBJS)
	make -C libft
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS) $^ -o $@

$(EXECDIR)%.o : $(EXECDIR)%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

$(BUILTINDIR)%.o : $(BUILTINDIR)%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

$(UTILSDIR)%.o : $(UTILSDIR)%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

%.o : %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

clean :
	make clean -C libft
	rm -f $(OBJS) $(DEPS)

fclean :
	make fclean -C libft
	rm -f $(OBJS) $(DEPS) $(NAME)

re : fclean
	make all

.PHONY: all clean fclean re
