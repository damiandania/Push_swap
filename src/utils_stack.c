/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 15:54:40 by dania             #+#    #+#             */
/*   Updated: 2023/09/04 16:47:06 by ddania-c         ###   ########.fr       */
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

void	st_add(t_st **stack, t_st *new)
{
	t_st	*aux;

	if (!new)
		return ;
	if (*stack == NULL)
	{
		*stack = new;
		return ;
	}
	aux = *stack;
	while (aux && aux->next != NULL)
		aux = aux->next;
	aux->next = new;
}

int	get_size(t_st *stack)
{
	int	size;

	size = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}

void	get_index(t_st *st_a, int size)
{
	t_st	*tmp;
	t_st	*max;

	while (size > 0)
	{
		tmp = st_a;
		max = NULL;
		while (tmp)
		{
			if (tmp->index == 0
				&& (max == NULL || tmp->value > max->value))
				max = tmp;
			tmp = tmp->next;
		}
		if (max != NULL)
			max->index = size;
		size--;
	}
}
