/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dania <dania@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:27:06 by ddania-c          #+#    #+#             */
/*   Updated: 2023/07/25 19:29:23 by dania            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	Toma un char y lo trnaforma en un int, este puede tener varios
	espacios al comienzo, un solo signno y para al encontrar algun
	digio que no sea numerico */

#include "../includes/libft.h"

// static size_t	ft_whitespace(const char *str)
// {
// 	size_t	i;

// 	i = 0;
// 	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
// 		i++;
// 	return (i);
// }

long int	ft_atoi(const char *str)
{
	int			i;
	long int	ret;
	int			sign;

	i = 0;
	sign = 1;
	ret = 0;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		ret = (ret * 10) + (str[i] - 48);
		i++;
	}
	return (ret * sign);
}
