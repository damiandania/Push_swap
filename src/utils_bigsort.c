/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bigsort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dania <dania@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:26:10 by dania             #+#    #+#             */
/*   Updated: 2023/08/08 00:31:43 by dania            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_position(t_st **stack)
{
	t_st	*tmp;
	int		i;

	i = 0;
	tmp = *stack;
	while (tmp)
	{
		tmp->pos = i;
		tmp = tmp->next;
		i++;
	}
}

static int get_target(t_st **st_a, int	b_index, int target)
{
	t_st	*tmp;
	int		i;
	
	i = INT_MAX;
	tmp = *st_a;
	while (tmp)
	{
		if (tmp->index > b_index && tmp->index < i)
		{
			i = tmp->index;
			target = tmp->pos;
		}
		tmp = tmp->next;
	}
	if (i != INT_MAX)
		return (target);
	tmp = *st_a;
	while (tmp)
	{
		if (tmp->index < i)
		{
			i = tmp->index;
			target = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (target);
}

void	get_target_position(t_st **st_a, t_st **st_b)
{
	t_st	*tmp_b;
	int		target;
	
	tmp_b = *st_b;
	target = 0;
	get_position(st_a);
	get_position(st_b);
	while (tmp_b)
	{
		target = get_target(st_a, tmp_b->index, target);
		tmp_b->target = target;
		tmp_b = tmp_b->next;
	}
}

void	get_cost(t_st **st_a, t_st **st_b)
{
	t_st	*tmp_a;
	t_st	*tmp_b;
	int		size_a;
	int		size_b;

	tmp_a = *st_a;
	tmp_b = *st_b;
	size_a = get_size(tmp_a);
	size_b = get_size(tmp_b);
	while (tmp_b)
	{
		tmp_b->cost_b = tmp_b->pos;
		if (tmp_b->pos > size_b / 2)
			tmp_b->cost_b = (size_b - tmp_b->pos) * -1;
		tmp_b->cost_a = tmp_b->target;
		if (tmp_b->target > size_a / 2)
			tmp_b->cost_a = (size_a - tmp_b->target) * -1;
		tmp_b = tmp_b->next;
	}
}

void	min_move(t_st **st_a, t_st **st_b)
{
	t_st	*tmp_b;
	int		index;
	int		min_move;
	
	tmp_b = *st_b;
	min_move = INT_MAX;
	index = 0;
	while (tmp_b)
	{
		if (pos_nb(tmp_b->cost_a) + pos_nb(tmp_b->cost_b) < min_move)
		{
			index = tmp_b->index;
			min_move = pos_nb(tmp_b->cost_a) + pos_nb(tmp_b->cost_b);
		}	
		tmp_b = tmp_b->next;
	}
	move(st_a, st_b, index);
}