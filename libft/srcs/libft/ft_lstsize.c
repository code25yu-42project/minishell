#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*temp;
	size_t	size;

	temp = lst;
	size = 0;
	while (temp != NULL)
	{
		temp = temp -> next;
		size++;
	}
	return (size);
}
