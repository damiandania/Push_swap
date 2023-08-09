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
	int		i;
	
	i = 1;
	st_b = NULL;
	while(i < ac)
	{
		get_args(av[i], &st_a);
		i++;
	}
	if (check_duplicate(st_a))
		exit_error(&st_a, NULL);
	size = get_size(st_a);
	get_index(st_a, size);
	push_swap(&st_a, &st_b, size);
	// ft_print(st_a);
	// ft_print(st_b);
	free_st(&st_a);
	free_st(&st_b);	
	return (0);
}