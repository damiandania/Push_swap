/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dania <dania@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 16:26:27 by dania             #+#    #+#             */
/*   Updated: 2023/07/25 20:18:44 by dania            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	t_st	*st_a;
	// t_st	*st_b;
	int		size;
	
	size = 0;
	if (ac < 2)
		return (0);
	if (!check_input(av))
		exit_error(NULL, NULL, ERR_INV);
	st_a = init_stack(ac, av);
	size = get_size(st_a);
	set_index(st_a, size);
	// push_swap(&st_a, &st_b, size);
	// free_st();
	// free_st();
	while (st_a)
	{
		printf("Valor: %d		-> Index: %d\n", st_a->value, st_a->index);
		st_a = st_a->next;
	}
	return (0);
}

