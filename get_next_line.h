/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 10:52:47 by jnakahod          #+#    #+#             */
/*   Updated: 2020/11/23 11:31:14 by nakahodoju       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# define MAX_FD 256

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

int				get_next_line(int fd, char **line);
int				fd_read(int *flag, int fd, char **line, char **save);
size_t			ft_strlen(char *s);
void			free_set(char **dst, char *src);
char			*make_join(size_t len_s1, size_t len_s2,
							char *s1, char *s2);
char			*ft_strjoin(char *s1, char *s2, size_t n);
size_t			ft_strlcpy(char *dst, char *src, size_t dstsize);
char			*ft_strdup(char *s1);
size_t			ft_strchr(char *s, int c);
int				put_line(char **line, char **save, char *buf);
int				get_next_line(int fd, char **line);
#endif
