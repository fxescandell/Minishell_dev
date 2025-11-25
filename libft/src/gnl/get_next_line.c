/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fescande <fescande@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 12:20:43 by fescande          #+#    #+#             */
/*   Updated: 2025/06/28 22:23:38 by fescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/* ************************************************************************* */

static char	*read_until_newline(int fd, char *dynamic_buffer)
{
	char	*static_buffer;
	ssize_t	read_bytes;
	char	*temp;

	static_buffer = malloc(BUFFER_SIZE + 1);
	if (static_buffer == NULL)
		return (free(dynamic_buffer), NULL);
	read_bytes = 1;
	while (read_bytes > 0 && !char_search(dynamic_buffer, '\n'))
	{
		read_bytes = read(fd, static_buffer, BUFFER_SIZE);
		if (read_bytes < 0)
			return (free(static_buffer), free(dynamic_buffer), NULL);
		static_buffer[read_bytes] = '\0';
		if (read_bytes == 0 && dynamic_buffer == NULL)
			return (free(static_buffer), NULL);
		temp = string_joined(dynamic_buffer, static_buffer);
		if (temp == NULL)
			return (free(static_buffer), free(dynamic_buffer), NULL);
		free(dynamic_buffer);
		dynamic_buffer = temp;
	}
	free(static_buffer);
	return (dynamic_buffer);
}

/* ************************************************************************* */
static char	*get_line_from_dynamic_buffer(char *dynamic_buffer)
{
	size_t	i;
	size_t	j;
	char	*line;

	i = 0;
	j = 0;
	if (dynamic_buffer == NULL || *dynamic_buffer == '\0')
		return (NULL);
	while (dynamic_buffer[i] && dynamic_buffer[i] != '\n')
		i++;
	if (dynamic_buffer[i] == '\n')
		i++;
	line = (char *)malloc(i + 1);
	if (line == NULL)
		return (NULL);
	while (j < i)
	{
		line[j] = dynamic_buffer[j];
		j++;
	}
	line[i] = '\0';
	return (line);
}

/* ************************************************************************* */
static char	*update_dynamic_buffer(char *dynamic_buffer)
{
	size_t	i;
	char	*new_buffer;

	i = 0;
	while (dynamic_buffer[i] && dynamic_buffer[i] != '\n')
		i++;
	if (dynamic_buffer[i] == '\0')
		return (free(dynamic_buffer), NULL);
	i++;
	new_buffer = string_duplicated(dynamic_buffer + i);
	free(dynamic_buffer);
	return (new_buffer);
}

/* ************************************************************************* */
#define MULTIPLE_FD 1024

char	*get_next_line(int fd)
{
	static char	*multiple_buffers[MULTIPLE_FD];
	char		*current_line;

	if (fd < 0 || fd >= MULTIPLE_FD || BUFFER_SIZE <= 0)
		return (NULL);
	multiple_buffers[fd] = read_until_newline(fd, multiple_buffers[fd]);
	if (!multiple_buffers[fd])
		return (NULL);
	current_line = get_line_from_dynamic_buffer(multiple_buffers[fd]);
	multiple_buffers[fd] = update_dynamic_buffer(multiple_buffers[fd]);
	return (current_line);
}
