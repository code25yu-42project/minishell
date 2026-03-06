#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *newlst)
{
	t_list	*temp;

	if (*lst == NULL)
		*lst = newlst;
	else if (newlst != NULL)
	{
		temp = ft_lstlast(*lst);
		temp -> next = newlst;
	}
}
