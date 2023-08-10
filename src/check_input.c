/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dania <dania@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:19:41 by dania             #+#    #+#             */
/*   Updated: 2023/08/08 01:25:24 by dania            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static int is_digit(int c) 
// {
// 	return (c >= '0' && c <= '9');
// }

// static int are_all_digits(char *av)
// {
// 	if (*av == '0' && av[1] != '\0')
// 		return (0);
// 	if (*av == '+' || *av == '-')
// 	{
// 		av++;
// 		if (*av == '0')
// 				return (0);
// 	}
// 	while (*av != '\0')
// 	{
// 		if (!is_digit(*av))
// 			return (0);
// 		else
// 			av++;
// 	}
// 	return 1;
// }

int check_input(char *av)
{
	int i;;

	i = 0;
	if ((av[i] == '-' || av[i] == '+') && (ft_strlen(av) > 1))
		i++;
	while (av[i])
	{
		if (av[i] < '0' || av[i] > '9')
			return	(0);
		i++;
	}
	return (1);
}

void	get_args(char *av, t_st **st_a)
{
	char		**args;
	long int	nb;
	int			i;

	if (!av)
		exit (1);
	args = ft_split(av, ' ');
	
	i = 0;
	while (args[i])
	{
		if (check_input(args[i]))
		{
			nb = ft_atoi(args[i]);
			if (nb > INT_MAX || nb < INT_MIN)
				exit_error(st_a, NULL);
			st_add(st_a, st_new(nb));
		}
		else
			exit_error(st_a, NULL);	
		free(args[i]);
		i++;
	}
	free(args);
}

int	check_duplicate(t_st *st_a)
{
	t_st	*tmp;
	t_st	*tmp2;

	tmp = st_a;
	while (tmp)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (tmp->value == tmp2->value)
				return (1);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	return (0);
}