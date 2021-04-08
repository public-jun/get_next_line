/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 10:52:35 by jnakahod          #+#    #+#             */
/*   Updated: 2020/11/23 11:24:41 by nakahodoju       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t			ft_strlen(char *s)
{
	size_t		i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

void			free_set(char **dst, char *src)
{
	free(*dst);
	*dst = src;
}

size_t			ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t		i;

	if (!dst || !src)
		return (0);
	if (dstsize == 0)
		return (ft_strlen(src));
	i = 0;
	while (src[i] && i < (dstsize - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

char			*ft_strdup(char *s1)
{
	char		*ptr;
	size_t		dstsize;

	dstsize = ((ft_strlen(s1) + 1) * sizeof(char));
	if (!(ptr = malloc(dstsize)))
		return (NULL);
	ft_strlcpy(ptr, s1, dstsize);
	return (ptr);
}

size_t			ft_strchr(char *s, int c)
{
	size_t		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (i + 1);
		i++;
	}
	return (0);
}
