/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dania <dania@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 22:41:09 by dania             #+#    #+#             */
/*   Updated: 2023/07/27 16:09:10 by dania            ###   ########.fr       */
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

static void	sort_of_5(t_st **st_a, t_st **st_b)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		if ((*st_a)->index == 0 || (*st_a)->index == 1)
		{
			move_pb(st_a, st_b);
			i++;
		}
		else
			move_ra(st_a);
	}
	sort_of_3(st_a);
	move_pa(st_a, st_b);
	move_pa(st_a, st_b);
	if ((*st_a)->index > (*st_a)->next->index)
		move_sa(st_a);
	ft_print(*st_a);
	ft_print(*st_b);
}

static void	big_sort(t_st **st_a, t_st **st_b, int size)
{
	
}

void	push_swap(t_st **st_a, t_st **st_b, int size)
{
	if (size <= 3 && !check_sort(*st_a))
		sort_of_3(st_a);
	else if (size <= 5 && !check_sort(*st_a))
		sort_of_5(st_a, st_b);
	else if (size > 5 && !check_sort(*st_a))
		big_sort(st_a, st_b, size);
}