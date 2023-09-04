/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 14:37:49 by dania             #+#    #+#             */
/*   Updated: 2023/09/04 15:36:07 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_st *stack)
{
	int	temp;

	if (stack == NULL || stack->next == NULL)
		return ;
	temp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = temp;
	temp = stack->index;
	stack->index = stack->next->index;
	stack->next->index = temp;
}

void	move_sa(t_st **st_a)
{
	swap(*st_a);
	write(1, "sa\n", 3);
}

void	move_sb(t_st **st_b)
{
	swap(*st_b);
	write(1, "sb\n", 3);
}

void	move_ss(t_st **st_a, t_st **st_b)
{
	swap(*st_a);
	swap(*st_b);
	write(1, "ss\n", 3);
}
