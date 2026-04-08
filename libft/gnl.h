/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuenca- <mcuenca-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 12:09:27 by mcuenca-          #+#    #+#             */
/*   Updated: 2026/04/08 12:44:15 by mcuenca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	GNL_H
# define GNL_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

#include <stdlib.h>

int	gnl(int fd, char **dest);
char	*get_next_line(int fd);
void	*ft_calloc_gnl(size_t nmemb, size_t size);
size_t	ft_strlen_gnl(const char *s);
char	*ft_strchr_gnl(const char *s, int c);
char	*ft_substr_gnl(char const *s, unsigned int start, size_t len);
char	*ft_strjoin_gnl(char const *s1, char const *s2);
void	ft_read_2ptr(char **content, char c);

#endif
