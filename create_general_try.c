#include "push_swap.h"

t_try				*create_general_try(t_try *old)
{
	t_try			*new;

	new = malloc(sizeof(t_try));
	new->first_length = old->first_length;
	new->second_length = old->second_length;
	new->depth = old->depth + 1;
	new->operators = malloc(new->depth * sizeof(t_operator));
	ft_memcpy(new->operators, old->operators, old->depth * sizeof(t_operator));
	return (new);
}
