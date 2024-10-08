/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 22:41:09 by dania             #+#    #+#             */
/*   Updated: 2023/09/04 15:24:44 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_of_3(t_st **stack)
{
	int	max_index;

	max_index = get_max_index(*stack);
	if ((*stack)->index == max_index)
		move_ra(stack);
	else if ((*stack)->next->index == max_index)
		move_rra(stack);
	if ((*stack)->index > (*stack)->next->index)
		move_sa(stack);
}

static void	big_sort(t_st **st_a, t_st **st_b, int size)
{
	first_push(st_a, st_b, size);
	sort_of_3(st_a);
	while (*st_b)
	{
		get_target_position(st_a, st_b);
		get_cost(st_a, st_b);
		min_move(st_a, st_b);
	}
	get_position(st_a);
	while ((*st_a)->index != 1)
		final_rotate(st_a, size);
}

void	push_swap(t_st **st_a, t_st **st_b, int size)
{
	if (size <= 3 && !check_sort(*st_a))
		sort_of_3(st_a);
	else if (size > 3 && !check_sort(*st_a))
		big_sort(st_a, st_b, size);
}
