#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *newlst)
{
	newlst -> next = *lst;
	*lst = newlst;
}
