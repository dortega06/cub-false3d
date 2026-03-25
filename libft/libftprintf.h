/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuenca- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:16:56 by mcuenca-          #+#    #+#             */
/*   Updated: 2026/03/21 14:48:53 by mcuenca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft.h"
# include <unistd.h>
# include <stdarg.h> //Macros
# include <stdlib.h>

int		ft_printf(const char *str, ...);
int		print_c(int c);
int		print_s(char *s);
int		print_p(void *p);
int		print_d(long int d);
int		print_u(unsigned long int u);
int		print_x_lowercase(unsigned int x);
int		print_x_uppercase(unsigned int x);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
#endif
