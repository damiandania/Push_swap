/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:19:41 by dania             #+#    #+#             */
/*   Updated: 2023/09/05 14:27:08 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	check_input(char *av)
{
	int	i;

	i = 0;
	if ((av[i] == '-' || av[i] == '+') && (ft_strlen(av) > 1))
		i++;
	while (av[i])
	{
		if (av[i] < '0' || av[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void	get_args(char *av, t_st **st_a)
{
	char		**args;
	long int	nb;
	int			i;

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
			exit_error(NULL, NULL);
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
