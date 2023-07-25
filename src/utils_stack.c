/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dania <dania@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 15:54:40 by dania             #+#    #+#             */
/*   Updated: 2023/07/25 23:44:19 by dania            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_st	*st_new(int value)
{
	t_st	*new;

	new = malloc(sizeof(t_st));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = 0;
	new->pos = -1;
	new->target = -1;
	new->cost_a = -1;
	new->cost_b = -1;
	new->next = NULL;
	return (new);
}

void	st_add_back(t_st **stack, t_st *new)
{
	t_st *aux;

	if (!new)
		return;
	if (*stack == NULL)
		*stack = new;
	else
	{
		aux = *stack;
		while (aux->next != NULL)
			aux = aux->next;
		aux->next = new;
	}
}

int	get_size(t_st *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}

void	set_index(t_st *st_a, int size)
{
	t_st	*current;
	t_st	*max;
	
	while (--size > 0)
	{
		current = st_a;
		max = NULL;
		while (current)
		{
			if (current->index == 0 && (max == NULL ||
					current->value > max->value))
				max = current;
			current = current->next;
		}
		if (max != NULL)
			max->index = size;
	}
}