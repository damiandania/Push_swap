/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dania <dania@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 22:41:21 by dania             #+#    #+#             */
/*   Updated: 2023/07/25 18:03:19 by dania            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_st **stack)
{
	t_st	*temp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;			
	}
	*stack = NULL;
}

void	exit_error(t_st **st_a, t_st **st_b, char *msg)
{
	if (st_a == NULL || *st_a != NULL)
		free_stack(st_a);
	if (st_b == NULL || *st_b != NULL)
		free_stack(st_b);
	write(2, "Error: ", 7);
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	exit (1);	
	
}

