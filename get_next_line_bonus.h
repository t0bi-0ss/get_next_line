/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsordo-o <tsordo-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 11:37:23 by tsordo-o          #+#    #+#             */
/*   Updated: 2026/05/26 18:42:16 by tsordo-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

// BUFFER_SIZE
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

// DELIMITER
# ifndef DELIMITER
#  define DELIMITER '\n'
# endif

// MAX fd NUMBER
#ifndef OPEN_MAX
# define OPEN_MAX 1024
#endif

// STRUCT
typedef struct s_list
{
	char	*content;
}			t_fd_list;

// Prototypes
char		*ft_strdup(const char *s, char stop);
char		*ft_strjoin(char const *s1, char const *s2);
char		*get_next_line(int fd);
#endif