#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*newtemp;
	void	*newcont;

	newlst = 0;
	if (f == NULL || del == NULL)
		return (NULL);
	while (lst)
	{
		newcont = (*f)(lst-> content);
		newtemp = ft_lstnew(newcont);
		if (newtemp == NULL)
		{
			del(newcont);
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		ft_lstadd_back(&newlst, newtemp);
		lst = lst -> next;
	}
	return (newlst);
}
