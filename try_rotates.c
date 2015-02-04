/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_rotates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 11:34:37 by tfleming          #+#    #+#             */
/*   Updated: 2015/02/04 11:36:23 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void			rotate(t_stack *stack)
{
	(void)stack;
}

static void			reverse_rotate(t_stack *stack)
{
	(void)stack;
}

void				try_rotate(t_search *search
										, t_stack *first, t_stack *second)
{
	rotate(first);
	search->operators[search->current] = ROTATE_A;
	calculate_operators(search, first, second);
	reverse_rotate(first);
	rotate(second);
	search->operators[search->current] = ROTATE_B;
	calculate_operators(search, first, second);
	rotate(first);
	search->operators[search->current] = ROTATE_A_B;
	calculate_operators(search, first, second);
	reverse_rotate(first);
	reverse_rotate(second);
}

void				try_reverse_rotate(t_search *search
										, t_stack *first, t_stack *second)
{
	reverse_rotate(first);
	search->operators[search->current] = REVERSE_ROTATE_A;
	calculate_operators(search, first, second);
	rotate(first);
	reverse_rotate(second);
	search->operators[search->current] = REVERSE_ROTATE_B;
	calculate_operators(search, first, second);
	reverse_rotate(first);
	search->operators[search->current] = REVERSE_ROTATE_A_B;
	calculate_operators(search, first, second);
	rotate(first);
	rotate(second);
}
