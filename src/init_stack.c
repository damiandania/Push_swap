/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dania <dania@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 17:21:55 by dania             #+#    #+#             */
/*   Updated: 2023/07/25 19:31:21 by dania            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_st	*init_stack(int ac, char **av)
{
	t_st		*st_a;
	long int	nb;
	int			i;

	i = 1;
	nb = 0;
	while (i < ac)
	{
		nb = ft_atoi(av[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			exit_error(&st_a, NULL, ERR_LIM);
		if (i == 1)
			st_a = st_new((int)nb);
		else
			st_add_back(&st_a, st_new((int)nb));
		i++;
	}
	return (st_a);
}
