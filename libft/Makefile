# Project name
NAME_STATIC_LIB = libft.a
NAME = libft

# Compiler
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

# Directories
INC_DIR = includes
SRC_DIR = srcs
TEST_DIR = tests

LIBFT_DIR = $(SRC_DIR)/libft
GNL_DIR = $(SRC_DIR)/get_next_line
PRINTF_DIR = $(SRC_DIR)/ft_printf

LIBFT_TEST_DIR = $(TEST_DIR)/libft
GNL_TEST_DIR = $(TEST_DIR)/get_next_line
PRINTF_TEST_DIR = $(TEST_DIR)/ft_printf

# Source files
# libft source files
LIBFT_SRC_FILES = \
	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_isspace.c \
	ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c \
	ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
	ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
	ft_split.c ft_strchr.c ft_strdup.c ft_strndup.c ft_striteri.c ft_strjoin.c ft_strsjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strcmp.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c \
	ft_free.c ft_cntchr.c
# get_next_line source files
GNL_SRC_FILES = get_next_line.c get_next_line_utils.c
# ft_printf source files
PRINTF_SRC_FILES =  \
	print.c print2.c sort.c lst.c isformat.c len.c \
	manage.c record.c center.c ft_printf.c

# directories for source files
LIBFT_SRCS = $(addprefix $(LIBFT_DIR)/, $(LIBFT_SRC_FILES))
GNL_SRCS = $(addprefix $(GNL_DIR)/, $(GNL_SRC_FILES))
PRINTF_SRCS = $(addprefix $(PRINTF_DIR)/, $(PRINTF_SRC_FILES))
SRC_FILES = $(LIBFT_SRCS) $(GNL_SRCS) $(PRINTF_SRCS)

# Object files
LIBFT_OBJS = $(LIBFT_SRCS:.c=.o)
GNL_OBJS = $(GNL_SRCS:.c=.o)
PRINTF_OBJS = $(PRINTF_SRCS:.c=.o)
OBJ_FILES = $(LIBFT_OBJS) $(GNL_OBJS) $(PRINTF_OBJS)

# Rules
all: $(NAME_STATIC_LIB)

libft: $(NAME_STATIC_LIB)
	$(CC) $(CFLAGS) -I$(INC_DIR) $(LIBFT_TEST_DIR)/main.c $(NAME_STATIC_LIB) -o $(NAME)
	./$(NAME)

gnl: $(NAME_STATIC_LIB)
	$(CC) $(CFLAGS) -I$(INC_DIR) $(GNL_TEST_DIR)/main.c $(NAME_STATIC_LIB) -o $(NAME)
	bash $(GNL_TEST_DIR)/test.sh

printf: $(NAME_STATIC_LIB)
	$(CC) $(CFLAGS) -I$(INC_DIR) $(PRINTF_TEST_DIR)/main.c $(NAME_STATIC_LIB) -o $(NAME)
	./$(NAME)

$(NAME_STATIC_LIB): $(OBJ_FILES)
	$(AR) $@ $^

$(LIBFT_DIR)/%.o: $(LIBFT_DIR)/%.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

$(GNL_DIR)/%.o: $(GNL_DIR)/%.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

$(PRINTF_DIR)/%.o: $(PRINTF_DIR)/%.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME_STATIC_LIB)
	rm -f $(NAME)

re: fclean all

.PHONY: all libft gnl printf clean fclean re
