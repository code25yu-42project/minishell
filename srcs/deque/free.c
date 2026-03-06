#include "deque.h"

// void	free_strs(char **strs)
// {
// 	size_t	index;

// 	index = 0;
// 	if (!strs)
// 		return ;
// 	while (strs[index])
// 	{
// 		free(strs[index]);
// 		strs[index++] = NULL;
// 	}
// 	free(strs);
// }

void	free_map(t_map *keyval)
{
	free(keyval->key);
	keyval->key = NULL;
	free(keyval->val);
	keyval->val = NULL;
}

void	free_deque(t_deque *deque)
{
	t_deque	*next;

	if (deque && deque->prev)
		deque->prev->next = NULL;
	while (deque)
	{
		next = deque->next;
		free_map(deque->data);
		free(deque->data);
		free(deque);
		deque = next;
	}
}

void	free_deques(t_deques **deques)
{
	if (*deques)
	{
		free_deque((*deques)->head);
		ft_memset(*deques, 0, sizeof(t_deques));
	}
	free(*deques);
	(*deques) = NULL;
}

void	remove_targetdeq(t_deques *deqs, t_deque *target)
{
	pop_target(deqs, target);
	free_deque(target);
}
