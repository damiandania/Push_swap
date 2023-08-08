/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dania <dania@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 22:45:31 by dania             #+#    #+#             */
/*   Updated: 2023/08/07 23:16:31 by dania            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move(t_st **st_a, t_st **st_b, int index)
{
	t_st	*tmp;
	int		i;

	tmp = *st_b;
	while (tmp->index != index)
		tmp = tmp->next;
	if (tmp->cost_b > 0)
	{
		i = 0;
		while (i < pos_nb(tmp->cost_b))
		{
			move_rb(st_b);
			i++;
		}
	}
	else
	{
		i = 0;
		while (i < pos_nb(tmp->cost_b))
		{
			move_rrb(st_b);
			i++;
		}
	}
	if (tmp->cost_a > 0)
	{
		i = 0;
		while (i < pos_nb(tmp->cost_a))
		{
			move_ra(st_a);
			i++;
		}
	}
	else
	{
		i = 0;
		while (i < pos_nb(tmp->cost_a))
		{
			move_rra(st_a);
			i++;
		}
	}
	move_pa(st_a, st_b);
}