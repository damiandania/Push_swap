/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dania <dania@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 22:41:21 by dania             #+#    #+#             */
/*   Updated: 2023/09/12 14:55:59 by dania            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_st(t_st **stack)
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

void	free_tab(void **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

void	exit_error(t_st **st_a, t_st **st_b)
{
	if (st_a == NULL || *st_a != NULL)
		free_st(st_a);
	if (st_b == NULL || *st_b != NULL)
		free_st(st_b);
	write(2, "Error\n", 6);
	exit (1);
}

int	pos_nb(int nb)
{
	if (nb < 0)
		nb = nb * -1;
	return (nb);
}
