/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_reverse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 14:38:54 by dania             #+#    #+#             */
/*   Updated: 2023/09/04 15:35:46 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse(t_st **stack)
{
	t_st	*tmp;
	t_st	*last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	tmp = *stack;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	last = tmp->next;
	last->next = *stack;
	*stack = last;
	tmp->next = NULL;
}

void	move_rra(t_st **st_a)
{
	reverse(st_a);
	write(1, "rra\n", 4);
}

void	move_rrb(t_st **st_b)
{
	reverse(st_b);
	write(1, "rrb\n", 4);
}

void	move_rrr(t_st **st_a, t_st **st_b)
{
	reverse(st_a);
	reverse(st_b);
	write(1, "rrr\n", 4);
}
