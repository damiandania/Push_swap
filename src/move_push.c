/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 14:39:33 by dania             #+#    #+#             */
/*   Updated: 2023/09/04 15:28:06 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_st **src, t_st **dest)
{
	t_st	*tmp;

	if (*src == NULL)
		return ;
	tmp = (*src)->next;
	(*src)->next = *dest;
	*dest = *src;
	*src = tmp;
}

void	move_pa(t_st **st_a, t_st **st_b)
{
	push(st_b, st_a);
	write(1, "pa\n", 3);
}

void	move_pb(t_st **st_a, t_st **st_b)
{
	push(st_a, st_b);
	write(1, "pb\n", 3);
}
