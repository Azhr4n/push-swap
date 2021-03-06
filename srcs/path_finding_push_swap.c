/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding_push_swap.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/14 19:22:05 by tfleming          #+#    #+#             */
/*   Updated: 2015/03/14 19:30:50 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** make_first_try: numbers has been mallocced in convert_to_indexes
*/

static t_try		*make_first_try(int length, int *numbers)
{
	t_try			*new;

	new = malloc(sizeof(t_try));
	new->first_length = length;
	new->second_length = 0;
	new->first = numbers;
	new->second = malloc(new->second_length * sizeof(int));
	new->depth = 0;
	new->operators = malloc(new->depth);
	set_score(new);
	return (new);
}

static void			setup_search(t_search *search, int length)
{
	int				i;

	ft_bzero(search, sizeof(t_search));
	search->pq = ft_pq_create_new((int (*)(void*, void*))&compare_tries);
	search->ascending_numbers = malloc(length * sizeof(int));
	i = 0;
	while (i < length)
	{
		search->ascending_numbers[i] = i;
		i++;
	}
}

static int			index_of(int needle, int *haystack)
{
	int				index;

	index = 0;
	while (haystack[index] != needle)
		index++;
	return (index);
}

static void			convert_to_indexes(int length, int **numbers)
{
	int				sorted[length];
	int				*wanted;
	int				i;

	ft_memcpy(sorted, *numbers, length * sizeof(int));
	ft_quicksort(length, sorted);
	wanted = malloc(length * sizeof(int));
	i = 0;
	while (i < length)
	{
		wanted[index_of(sorted[i], *numbers)] = i;
		i++;
	}
	ft_ptrswp((void**)&wanted, (void**)numbers);
}

void				path_finding_push_swap(int length, int *numbers
											, t_operator **solution
											, int *solution_length)
{
	t_search		search;
	t_try			*peek;

	setup_search(&search, length);
	convert_to_indexes(length, &numbers);
	ft_pq_add(search.pq, make_first_try(length, numbers));
	while ((peek = ((t_try*)ft_pq_peek(search.pq))))
		permutate(&search);
	*solution = search.solution;
	*solution_length = search.solution_length;
}
