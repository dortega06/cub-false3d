/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuenca- <mcuenca-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 17:16:05 by mcuenca-          #+#    #+#             */
/*   Updated: 2026/04/04 20:16:52 by mcuenca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"
#include "cube3d.h"

int	main(int argc, char **argv)
{
	t_cube	root_nd;

	if (argc != 2)
		return (ft_printf("Expected 1 argument.\n"), 0);
	root_nd.fd = -1;
	root_nd.file = NULL;
	if (!parse_cub(argv[1], &root_nd))
		return (clean_data_cube(&root_nd), 1);
	clean_data_cube(&root_nd);
	return (0);
}
