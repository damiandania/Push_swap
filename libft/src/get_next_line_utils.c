/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:11:52 by ddania-c          #+#    #+#             */
/*   Updated: 2023/09/04 15:14:32 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strchr_gnl(const char *str)
{
	size_t	i;

	i = 0;
	if (str == 0)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

char	*buffer_to_reserve(char *reserve, char *buffer)
{
	int		i;
	int		j;
	char	*dest;

	if (!reserve)
	{
		reserve = malloc(sizeof(char) * 1);
		reserve[0] = '\0';
	}
	if (!reserve || !buffer)
		return (NULL);
	dest = malloc(sizeof(char *)
			* ((int)ft_strlen(reserve) + (int)ft_strlen(buffer) + 1));
	if (!dest)
		return (NULL);
	i = -1;
	while (reserve[++i] != '\0')
		dest[i] = reserve[i];
	j = 0;
	while (buffer[j] != '\0')
		dest[i++] = buffer[j++];
	dest[i] = '\0';
	free(reserve);
	return (reserve = dest);
}
