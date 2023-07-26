/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dania <dania@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 22:41:09 by dania             #+#    #+#             */
/*   Updated: 2023/07/27 00:39:08 by dania            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_sort(t_st *stack)
{
	while (stack->next != NULL)   
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static void	sort_3(t_st **stack)
{
	while (check_sort(*stack) != 1)
	{
		if ((*stack)->index > (*stack)->next->index)
			move_sa(stack);
		else if ((*stack)->next->index >
				(*stack)->next->next->index)
			move_rra(stack);
		ft_print(*stack);
	}
}

// // void	sort_5(t_st **st_a, t_st **st_b, int size)
// // {
	
// // }

// // void	sort(t_st **st_a, t_st **st_b, int size)
// // {
	
// // }

void	push_swap(t_st **st_a,/*  t_st **st_b, */ int size)
{
	if (size <= 3 && !check_sort(*st_a))
		sort_3(st_a);
	// else if (size <= 5 && !check_sort(*st_a))
	// 	sort_5(st_a, st_b);
	// else if (size > 5 && !check_sort(*st_a))
	// 	sort(st_a, st_b);
}