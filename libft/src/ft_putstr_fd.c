/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dania <dania@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 19:20:50 by ddania-c          #+#    #+#             */
/*   Updated: 2023/07/25 16:35:35 by dania            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Imprime una cadenad de caracteres str segun el formato de fd

#include "../includes/libft.h"

void	ft_putstr_fd(char *str, int fd)
{
	int	ret;

	if (str)
	{
		ret = write (fd, str, ft_strlen(str));
		if (ret == -1)
		{
			perror("write error");
			exit(1);
		}
	}
}