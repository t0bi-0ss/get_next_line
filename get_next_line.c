/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsordo-o <tsordo-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 14:49:58 by tsordo-o          #+#    #+#             */
/*   Updated: 2026/05/14 19:40:23 by tsordo-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ends_with_nl(char *str)
{
	int len;

	if (!str)
		return (0);
	len = 0;
	while (str[len] && str[len] != '\n')
		len++;
	if (str[len] == '\n')
		return (1);
	return (0);
}

size_t	next_new_line(char *str)
{
	size_t	stop;

	if (!str)
		return (0);
	stop = 0;
	while (str[stop] && str[stop] != '\n')
		stop++;
	return (stop);
}

char	*get_next_line(int fd)
{
	fd_list			fd_arr[1024];
	char			*new_line;
	char			*buffer;
	char 			*tmp_str;
	int				bytes_read;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	buffer = malloc ((BUFFER_SIZE + 1) * sizeof(char));
	bytes_read = 0;
	if (!buffer)
		return (NULL);
	while (!ends_with_nl(fd_arr[fd].content))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == 0)
			break;
		if (bytes_read < 0)
			return (NULL);
		buffer[bytes_read] = '\0';
		tmp_str = ft_strjoin(fd_arr[fd].content, buffer);	
		free(fd_arr[fd].content);
		fd_arr[fd].content = tmp_str;
	}
	new_line = ft_strdup(fd_arr[fd].content);
	free(fd_arr[fd].content);
	fd_arr[fd].content = NULL;
	free(buffer);
	if (!new_line)
	{
		return (NULL);
	}
	return (new_line);
}
