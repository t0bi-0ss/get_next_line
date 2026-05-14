/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsordo-o <tsordo-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 11:39:56 by tsordo-o          #+#    #+#             */
/*   Updated: 2026/05/14 19:43:16 by tsordo-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *) s;
	while (n)
	{
		*ptr = 0;
		ptr++;
		n--;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	total_size;

	if (nmemb == 0 || size == 0)
	{
		ptr = malloc(1);
		if (!ptr)
			return (NULL);
		return (ptr);
	}
	total_size = nmemb * size;
	if (total_size / nmemb != size)
		return (NULL);
	ptr = malloc (total_size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, total_size);
	return (ptr);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t			dst_len;
	size_t			src_len;
	size_t			dst_end;
	unsigned int	index;

	dst_len = 0;
	src_len = 0;
	if (dst)
		while (dst[dst_len])
			dst_len++;
	if (!src)
		return(0);
	while (src[src_len])
		src_len++;
	if (size == 0)
		return (src_len);
	if (dst_len >= size)
		return (src_len + size);
	dst_end = dst_len;
	index = 0;
	while (index < (size - dst_len - 1) && src[index])
		dst[dst_end++] = src[index++];
	dst[dst_end] = '\0';
	return (src_len + dst_len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*final_str;
	size_t	size;
	size_t  s1_len;
	size_t s2_len;

	s1_len = 0;
	s2_len = 0;
	if (s1)
		while (s1[s1_len])
			s1_len++;
	if (s2)
		while (s2[s2_len])
			s2_len++;
	size = s1_len + s2_len + 1;
	final_str = malloc(size * sizeof(char));
	if (!final_str)
		return (NULL);
	ft_bzero(final_str, size);
	ft_strlcat(final_str, s1, size);
	ft_strlcat(final_str, s2, size);
	return (final_str);
}

char	*ft_strdup(const char *s)
{
	size_t	s_len;
	char	*ptr;

	if (!s || *s == '\0')
		return (NULL);
	s_len = 0;
	while (s[s_len])
		s_len++;
	ptr = ft_calloc(1, s_len + 1);
	if (!ptr)
		return (NULL);
	ft_strlcat(ptr, s, s_len + 1);
	return (ptr);
}
