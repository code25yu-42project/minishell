#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 10496
# endif

typedef struct s_fd_record
{
	int					fd;
	int					readrt;
	int					mallen;
	char				*record;
	struct s_fd_record	*next;
}						t_fd_record;

char	*get_next_line(int fd);
int		ft_strchr_pos(char *str, char chr);
int		ft_newadd_lst(t_fd_record **rcdlst_ptr, t_fd_record **fdlst_ptr, int fd);
int		ft_fdlst(t_fd_record **rcdlst_ptr, t_fd_record **fdlst_ptr, int fd);
int		ft_parse_rcd(t_fd_record **fdlst_ptr, char **res_ptr, int reslen);
int		ft_extract_line(t_fd_record **rcdlst_ptr, t_fd_record **fdlst_ptr, char **res_ptr);
void	ft_freelst(t_fd_record **rcdlst_ptr, t_fd_record **fdlst_ptr, char *res);
#endif
