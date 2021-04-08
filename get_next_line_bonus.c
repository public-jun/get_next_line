/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 14:35:59 by jnakahod          #+#    #+#             */
/*   Updated: 2020/12/18 21:46:47 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char			*make_join(size_t len_s1, size_t len_s2,
							char *s1, char *s2)
{
	char		*ans;
	int			i;

	i = 0;
	if (!(ans = malloc(sizeof(char) * (len_s1 + len_s2 + 1))))
		return (NULL);
	if (s1)
	{
		while (len_s1--)
			ans[i++] = *s1++;
	}
	if (s2)
	{
		while (len_s2--)
			ans[i++] = *s2++;
	}
	ans[i] = '\0';
	return (ans);
}

char			*ft_strjoin(char *s1, char *s2, size_t n)
{
	char		*ans;
	size_t		len_s1;
	size_t		len_s2;

	if (!s1 && !s2)
	{
		if (!(ans = malloc(1)))
			return (NULL);
		*ans = '\0';
		return (ans);
	}
	len_s1 = ft_strlen(s1);
	if (n > 0)
		len_s2 = n - 1;
	else
		len_s2 = ft_strlen(s2);
	return (make_join(len_s1, len_s2, s1, s2));
}

int				put_line(char **line, char **save, char *buf)
{
	int			flag;
	size_t		n;
	char		*tmp;

	n = ft_strchr(buf, '\n');
	if (!(tmp = ft_strjoin(*line, buf, n)))
		return (-1);
	free_set(line, tmp);
	tmp = NULL;
	flag = 0;
	if (n > 0)
	{
		if (!(tmp = ft_strdup(buf + n)))
			return (-1);
		flag = 1;
	}
	free_set(save, tmp);
	tmp = NULL;
	return (flag);
}

int				fd_read(int *flag, int fd, char **line, char **save)
{
	char		*buf;
	ssize_t		read_size;

	if (!(buf = malloc(sizeof(char) * ((size_t)BUFFER_SIZE + 1))))
		*flag = -1;
	buf[0] = '\0';
	read_size = 0;
	while (*flag == 0 && (read_size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[read_size] = '\0';
		*flag = put_line(line, save, buf);
	}
	if (read_size < 0)
		*flag = -1;
	free_set(&buf, NULL);
	return (*flag);
}

int				get_next_line(int fd, char **line)
{
	static char	*fd_save[MAX_FD];
	int			flag;

	if (fd < 0 || line == NULL || fd > MAX_FD || BUFFER_SIZE < 1)
		return (-1);
	*line = ft_strjoin(NULL, NULL, 1);
	flag = 0;
	if (fd_save[fd])
		flag = put_line(line, &fd_save[fd], fd_save[fd]);
	flag = fd_read(&flag, fd, line, &fd_save[fd]);
	if (flag == -1)
	{
		free_set(&fd_save[fd], NULL);
		free_set(line, NULL);
	}
	return (flag);
}
