#include "deque.h"

t_deques	*create_deques(void)
{
	t_deques	*new_deques;

	new_deques = ft_calloc(1, sizeof(t_deques));
	return (new_deques);
}

t_deque	*create_deque(void)
{
	t_deque	*new_deque;

	new_deque = ft_calloc(1, sizeof(t_deque));
	return (new_deque);
}

t_map	*create_keyval(void)
{
	t_map	*new_map;

	new_map = ft_calloc(1, sizeof(t_map));
	return (new_map);
}
