/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsordo-o <tsordo-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 14:49:58 by tsordo-o          #+#    #+#             */
/*   Updated: 2026/05/19 16:30:07 by tsordo-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if ((unsigned char)*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

int	fill_arr_element(t_fd_list *fd_arr_element, char **buffer, int fd)
{
	char	*tmp_str;
	int		bytes_read;

	bytes_read = 0;
	while (!ft_strchr(fd_arr_element->content, '\n'))
	{
		bytes_read = read(fd, *buffer, BUFFER_SIZE);
		if (bytes_read == 0)
			break ;
		if (bytes_read < 0)
		{
			free(*buffer);
			free(fd_arr_element->content);
			fd_arr_element->content = NULL;
			return (0);
		}
		(*buffer)[bytes_read] = '\0';
		tmp_str = ft_strjoin(fd_arr_element->content, *buffer);
		free(fd_arr_element->content);
		fd_arr_element->content = tmp_str;
	}
	return (1);
}

int	get_new_line(char **new_line, char **buffer, t_fd_list *fd_arr_element)
{
	char	*left_overs;

	*new_line = ft_strdup(fd_arr_element->content, '\n');
	if (!ft_strchr(fd_arr_element->content, '\n'))
		left_overs = NULL;
	else
		left_overs = ft_strdup(ft_strchr(fd_arr_element->content, '\n') + 1, 0);
	free(fd_arr_element->content);
	fd_arr_element->content = left_overs;
	free(*buffer);
	if (!*new_line)
	{
		free(fd_arr_element->content);
		fd_arr_element->content = NULL;
		return (0);
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static t_fd_list	fd_arr[1024];
	char				*new_line;
	char				*buffer;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	if (!fill_arr_element(&fd_arr[fd], &buffer, fd))
		return (NULL);
	if (!get_new_line(&new_line, &buffer, &fd_arr[fd]))
		return (NULL);
	return (new_line);
}
