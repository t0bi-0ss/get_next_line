/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsordo-o <tsordo-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 11:37:23 by tsordo-o          #+#    #+#             */
/*   Updated: 2026/05/14 20:23:03 by tsordo-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

// BUFFER_SIZE
#ifndef BUFFER_SIZE
	#define BUFFER_SIZE 30
#endif

// STRUCT
typedef struct s_list
{
	char			*content;
}					fd_list;

//Libraries
#include <stdlib.h>
#include <unistd.h>

//Prototypes
char	*ft_strdup(const char *s, char *stop);
char	*ft_strjoin(char const *s1, char const *s2);
char	*get_next_line(int fd);
#endif