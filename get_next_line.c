/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsordo-o <tsordo-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 11:36:01 by tsordo-o          #+#    #+#             */
/*   Updated: 2026/05/11 20:29:48 by tsordo-o         ###   ########.fr       */
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

void	join_line(char	**nl_ptr, fd_list *node, int fd)
{
	char *buffer;
	char	*rest_of_line;
	char	*joined_lines;
	int		bytes_read;
	size_t	nl_locator;

	buffer = malloc(BUFFER_SIZE * sizeof(char));
	if (!buffer)
		return ;
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (!bytes_read)
		{
			free(buffer);
			buffer = NULL;
			node->content = NULL;
			return ;
		}
	buffer[bytes_read] = '\0';
	nl_locator = next_new_line(buffer);
	rest_of_line = ft_strdup(buffer, nl_locator, 0);
	joined_lines = ft_strjoin(*nl_ptr, rest_of_line);
	free(*nl_ptr);
	*nl_ptr = joined_lines;
	free(node->content);
	node->content = ft_strdup(buffer, 0, nl_locator);
	free(buffer);
	buffer = NULL;
}

fd_list	*get_node(fd_list **head, int fd)
{
	fd_list	*tmp;
	char	*buffer;

	tmp = *head;
	while (tmp != NULL && tmp->fd_id != fd)
		tmp = tmp->next;
	if (!tmp)
	{
		tmp = malloc(sizeof(fd_list));
		if (!tmp)
			return (NULL);
		tmp->fd_id = fd;
		tmp->next = *head;
		*head = tmp;
		buffer = malloc((BUFFER_SIZE + 1)* sizeof(char));
		if (!buffer)
			return (NULL);
		read(fd, buffer, BUFFER_SIZE);
		buffer[BUFFER_SIZE] = '\0';
		tmp->content = ft_strdup(buffer, 0, 0);
		free(buffer);
		buffer = NULL;
	}
	return (tmp);
}

char	*get_next_line(int fd)
{
	static fd_list	*head;
	fd_list			*tmp;
	char			*leftovers;
	char			*new_line;
	size_t	nl_locator;

	tmp = get_node(&head, fd);
	nl_locator = next_new_line(tmp->content);
	new_line = ft_strdup(tmp->content, nl_locator + 1, 0);
	if (!ends_with_nl(new_line)) //Could be the end of the file or a part of a line before the '\n'
	{
		join_line(&new_line, tmp, fd);
		if (!new_line)
			return (0);
		return (new_line);
	}
	leftovers = ft_strdup(tmp->content, 0, nl_locator + 1);
	free(tmp->content);
	tmp->content = leftovers;
	return (new_line);
}
