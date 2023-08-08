/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dania <dania@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:26:10 by dania             #+#    #+#             */
/*   Updated: 2023/08/07 23:24:11 by dania            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_index(t_st *stack)
{
	int	max_index;

	max_index = 0;
	while (stack)
	{
		if (stack->index > max_index)
			max_index = stack->index;
		stack = stack->next;
	}
	return (max_index);	
}

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

void first_push(t_st **st_a, t_st **st_b, int size)
{
	int	counter;
	int	i;
	counter = 0;
	i = 0;
	while (i < size && counter < (size / 2))
	{
		if ((*st_a)->index <= (size / 2))
		{
			move_pb(st_a, st_b);
			counter++;
		}
		else
			move_ra(st_a);
		i++;	
	}
	while (counter != (size - 3))
	{
		move_pb(st_a, st_b);
		counter++;
	}
}