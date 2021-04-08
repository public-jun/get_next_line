/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 14:36:28 by jnakahod          #+#    #+#             */
/*   Updated: 2020/11/23 14:37:06 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

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
