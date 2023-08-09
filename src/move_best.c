/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_best.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dania <dania@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 22:45:31 by dania             #+#    #+#             */
/*   Updated: 2023/08/08 16:38:46 by dania            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_a(t_st **st_a, int *cost_a)
{
	while (*cost_a)
	{
		if (*cost_a < 0)
		{
			move_rra(st_a);
			(*cost_a)++;
		}
		else if (*cost_a > 0)
		{
			move_ra(st_a);
			(*cost_a)--;
		}
	}
}

static void	rotate_b(t_st **st_b, int *cost_b)
{
	while (*cost_b)
	{
		if (*cost_b < 0)
		{
			move_rrb(st_b);
			(*cost_b)++;
		}
		else if (*cost_b > 0)
		{
			move_rb(st_b);
			(*cost_b)--;
		}
	}
}

static void	double_rrr(t_st **st_a, t_st ** st_b, int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		move_rrr(st_a, st_b);
		(*cost_a)++;
		(*cost_b)++;
	}
}

static void	double_rr(t_st **st_a, t_st ** st_b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		move_rr(st_a, st_b);
		(*cost_a)--;
		(*cost_b)--;
	}
}

void	move(t_st **st_a, t_st **st_b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		double_rrr(st_a, st_b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		double_rr(st_a, st_b, &cost_a, &cost_b);
	rotate_a(st_a, &cost_a);
	rotate_b(st_b, &cost_b);
	move_pa(st_a, st_b);
}