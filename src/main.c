/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dania <dania@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 16:26:27 by dania             #+#    #+#             */
/*   Updated: 2023/07/27 15:16:48 by dania            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void ft_print(t_st *stack)
{
	t_st	*tmp;

	tmp = stack;
	while (tmp)
	{
		printf("v: %d	i: %d\n",
				tmp->value, tmp->index);
		tmp = tmp->next;
	}
	printf("\n");
}


int main(int ac, char **av)
{
	t_st	*st_a;
	t_st	*st_b;
	
	int		size;
	
	size = 0;
	if (ac < 2)
		return (0);
	if (!check_input(av))
		exit_error(NULL, NULL, ERR_INV);
	st_a = init_stack(ac, av);
	st_b = NULL;
	size = get_size(st_a);
	set_index(st_a, size);
	
	ft_print(st_a);
	push_swap(&st_a, &st_b, size);

	// free_st();
	// free_st();

	// ft_print(st_a);
	// ft_print(st_b);
	
	// move_pb(&st_a, &st_b);
	// move_pb(&st_a, &st_b);
	// move_pb(&st_a, &st_b);
	// move_pb(&st_a, &st_b);
	// printf("\n");
	// ft_print(st_a);
	// ft_print(st_b);

	// move_ra(&st_a);
	// printf("\n");
	// ft_print(st_a);
	// ft_print(st_b);

	// move_ra(&st_a);
	// printf("\n");
	// ft_print(st_a);
	// ft_print(st_b);

	// move_ra(&st_a);
	// printf("\n");
	// ft_print(st_a);
	// ft_print(st_b);

	// move_rra(&st_a);
	// printf("\n");
	// ft_print(st_a);
	// ft_print(st_b);

	return (0);
}