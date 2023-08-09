/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dania <dania@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 16:26:27 by dania             #+#    #+#             */
/*   Updated: 2023/08/08 15:18:11 by dania            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// void ft_print(t_st *stack)
// {
// 	t_st	*tmp;

// 	tmp = stack;
// 	while (tmp)
// 	{
// 		printf("v: %d	i: %d	p: %d	t: %d	ca: %d	cb: %d\n",
// 				tmp->value, tmp->index, tmp->pos, tmp->target, tmp->cost_a, tmp->cost_b);
// 		tmp = tmp->next;
// 	}
// 	printf("\n");
// }

int main(int ac, char **av)
{
	t_st	*st_a;
	t_st	*st_b;
	int		size;
	
	if (ac < 2)
		return (0);
	if (!check_input(av))
		exit_error(NULL, NULL, ERR_INV);
	st_a = init_stack(ac, av);
	st_b = NULL;
	size = get_size(st_a);
	set_index(st_a, size);
	push_swap(&st_a, &st_b, size);
	// ft_print(st_a);
	// ft_print(st_b);
	free_st(&st_a);
	free_st(&st_b);	
	return (0);
}