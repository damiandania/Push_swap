/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dania <dania@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 14:38:24 by dania             #+#    #+#             */
/*   Updated: 2023/07/26 17:03:36 by dania            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_st **stack)
{
	t_st	*tmp;
	t_st	*last;

	if (*stack == NULL || (*stack)->next == NULL)
		return;
	tmp = *stack;
	*stack = (*stack)->next;
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	tmp->next = NULL;
	last->next = tmp;
}

void	move_ra(t_st **st_a)
{
	rotate(st_a);
	write(1, "ra\n", 3);
}

void	move_rb(t_st **st_b)
{
	rotate(st_b);
	write(1, "rb\n", 3);
}

void	move_rr(t_st **st_a, t_st **st_b)
{
	rotate(st_a);
	rotate(st_b);
	write(1, "rr\n", 3);
}