/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_gnl_content.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuenca- <mcuenca-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 17:53:46 by mcuenca-          #+#    #+#             */
/*   Updated: 2026/04/01 11:02:12 by mcuenca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	read_gnl_content(char **content)
{
	int	i;

	i = 0;
	if (!content)
		return ;
	while (content[i])
	{
		ft_printf("%s\n", content[i]);
		i++;
	}
}
