/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:19:41 by dania             #+#    #+#             */
/*   Updated: 2023/09/12 16:29:47 by ddania-c         ###   ########.fr       */
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
	long int	nb;
	int			i;
	char		**tab;
	int			status;

	status = 0;
	i = 0;
	tab = ft_split(av, ' ');
	while (tab[i])
	{
		if (!check_input(tab[i]))
			status = 1;
		nb = ft_atoi(tab[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			status = 1;
		st_add(st_a, st_new(nb));
		i++;
	}
	free_tab((void **)tab);
	if (status == 1)
		exit_error(st_a, NULL);
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
