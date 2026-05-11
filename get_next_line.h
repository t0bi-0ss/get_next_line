/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsordo-o <tsordo-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 11:37:23 by tsordo-o          #+#    #+#             */
/*   Updated: 2026/05/11 20:24:52 by tsordo-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

// BUFFER_SIZE
#ifndef BUFFER_SIZE
	#define BUFFER_SIZE 1
#endif

// STRUCT FOR LINKED LIST
typedef struct s_list
{
	char			*content;
	int				fd_id;
	struct s_list	*next;
}					fd_list;

//Libraries
#include <stdlib.h>
#include <unistd.h>

//Prototypes
char	*ft_strdup(const char *s, int stop, int start);
char	*ft_strjoin(char const *s1, char const *s2);
char	*get_next_line(int fd);
#endif