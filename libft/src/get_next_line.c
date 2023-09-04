/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:12:01 by ddania-c          #+#    #+#             */
/*   Updated: 2023/09/04 15:18:06 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*get_new_reserve(char *reserve, char *line)
{
	char	*new_reserve;
	int		i;
	int		j;

	if (!reserve)
		return (NULL);
	i = 0;
	while (reserve[i] != '\0' && reserve[i] == line[i])
		i++;
	if (reserve[i] == '\0')
	{
		free(reserve);
		return (NULL);
	}
	new_reserve = malloc(sizeof(char *)
			* ((int)ft_strlen(reserve) - (int)ft_strlen(line) + 1));
	if (!new_reserve)
		return (NULL);
	j = 0;
	while (reserve[i] != '\0')
		new_reserve[j++] = reserve[i++];
	new_reserve[j] = '\0';
	free(reserve);
	return (new_reserve);
}

char	*reserve_to_line(char *reserve)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	if (reserve[i] == '\0')
		return (NULL);
	while ((reserve[i] != '\n') && (reserve[i] != '\0'))
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	j = -1;
	while (++j < i)
		line[j] = reserve[j];
	if (reserve[j] == '\n')
		line[j++] = '\n';
	line[j++] = '\0';
	return (line);
}

char	*read_and_reserve(int fd, char *reserve)
{
	char	*buffer;
	int		n_readed;

	n_readed = 1;
	buffer = malloc(sizeof(char *) * (BUFFER_SIZE + 1));
	if (!buffer)
	{
		free(reserve);
		return (NULL);
	}
	while (n_readed != 0 && ft_strchr_gnl(reserve) == NULL)
	{
		n_readed = read(fd, buffer, BUFFER_SIZE);
		if (n_readed == -1)
		{
			free(buffer);
			free(reserve);
			return (NULL);
		}
		buffer[n_readed] = '\0';
		reserve = buffer_to_reserve(reserve, buffer);
	}
	free(buffer);
	return (reserve);
}

char	*get_next_line(int fd)
{
	static char	*reserve;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1023)
		return (NULL);
	reserve = read_and_reserve(fd, reserve);
	if (reserve == NULL)
		return (NULL);
	line = reserve_to_line(reserve);
	reserve = get_new_reserve(reserve, line);
	return (line);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		write(1, line, ft_strlen(line));
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
