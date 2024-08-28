/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dania <dania@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 16:26:27 by dania             #+#    #+#             */
/*   Updated: 2023/09/12 15:12:36 by dania            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_st	*st_a;
	t_st	*st_b;
	int		size;
	int		i;

	i = 1;
	st_b = NULL;
	st_a = NULL;
	if (ac < 2)
		return (0);
	while (ac != i)
	{
		if (!av[i] || av[i][0] == '\0')
			exit_error(&st_a, NULL);
		get_args(av[i], &st_a);
		i++;
	}
	if (check_duplicate(st_a))
		exit_error(&st_a, NULL);
	size = get_size(st_a);
	get_index(st_a, size);
	push_swap(&st_a, &st_b, size);
	free_st(&st_a);
	free_st(&st_b);
	return (0);
}
