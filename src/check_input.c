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

static int is_digit(int c) 
{
	return (c >= '0' && c <= '9');
}

static int are_all_digits(char *av)
{
	if (*av == '0' && av[1] != '\0')
		return (0);
	if (*av == '+' || *av == '-')
	{
		av++;
		if (*av == '0')
				return (0);
	}
	while (*av != '\0')
	{
		if (!is_digit(*av))
			return (0);
		else
			av++;
	}
	return 1;
}

int check_input(char **av)
{
	int i;
	int j;

	i = 1;
	while (av[i])
	{
		if (!are_all_digits(av[i]))
			return (0);
		j = i + 1;
		while (av[j])
		{
			if (ft_strcmp(av[i], av[j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}