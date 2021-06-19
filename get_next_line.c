/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veduardo <veduardo@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 16:06:21 by veduardo          #+#    #+#             */
/*   Updated: 2021/06/19 20:18:23 by veduardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nb, size_t size)
{
	void	*ptr;
	char	*set;
	size_t	i;

	i = 0;
	ptr = malloc(nb * size);
	set = (char *)ptr;
	if (!set)
		return (NULL);
	while (i < size)
	{
		set[i] = '\0';
		i++;
	}
	return (ptr);
}

static char	*create_new_line(char **line, char **buffer)
{
	int		found_line_break;
	char	*temp;

	temp = NULL;
	found_line_break = ft_strchr(*buffer, '\n');
	if (found_line_break != -1)
	{
		buffer[0][found_line_break] = '\0';
		*line = ft_strdup(*buffer);
		found_line_break++;
		temp = ft_strdup(*buffer + found_line_break);
	}
	else
		*line = ft_strdup(*buffer);
	free(*buffer);
	buffer = NULL;
	if (!line || !temp)
		return (NULL);
	return (temp);
}

int	start_read(int fd, char **buffer, char *next_line, int *read_bytes)
{
	char	*temp;
	size_t	i;

	while (*read_bytes && (ft_strchr(*buffer, '\n') == -1))
	{
		*read_bytes = read(fd, next_line, BUFFER_SIZE);
		if (*read_bytes < 0 || BUFFER_SIZE < *read_bytes)
		{
			free(next_line);
			return (-1);
		}
		if (*read_bytes)
		{
			temp = NULL;
			if (*read_bytes < BUFFER_SIZE)
				temp = ft_strjoin(temp, next_line, *read_bytes);
			else
				temp = ft_strjoin(temp, next_line, BUFFER_SIZE + 1);
			i = ft_strlen(*buffer);
			*buffer = ft_strjoin(*buffer, temp, BUFFER_SIZE + i);
			free(temp);
		}
	}
	free(next_line);
	return (1);
}

int	errors(int fd, char **line)
{
	if (fd < 0)
		return (1);
	if (fd > RLIMIT_NOFILE)
		return (1);
	if (BUFFER_SIZE <= 0)
		return (1);
	if (line == NULL)
		return (1);
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*buffer;
	char		*next_line;
	int			already_read;
	int			read_bytes;

	if (errors(fd, line))
		return (-1);
	next_line = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!next_line)
		return (-1);
	if (!buffer)
		buffer = ft_strdup("");
	read_bytes = 1;
	already_read = start_read(fd, &buffer, next_line, &read_bytes);
	if (already_read == -1)
		return (-1);
	buffer = create_new_line(line, &buffer);
	if (!read_bytes)
	{
		free(buffer);
		return (0);
	}
	return (1);
}
