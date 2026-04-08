/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuenca- <mcuenca-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 17:16:05 by mcuenca-          #+#    #+#             */
/*   Updated: 2026/04/08 13:34:55 by mcuenca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"
#include "mlx.h"
#include "mlx_int.h"
#include "cube3d.h"

int	main(int argc, char **argv)
{
	int		j;
	t_cube	root_nd;

	if (argc != 2)
		return (ft_printf("Expected 1 argument.\n"), 0);
	root_nd.fd = -1;
	root_nd.width = 512;
	root_nd.height = 512;
	root_nd.file = NULL;
	root_nd.sys = mlx_init();
	j = 0;
	while (j < 4)
		root_nd.textu[++j].image = NULL;
	if (!parse_cub(argv[1], &root_nd))
		return (clean_data_cube(&root_nd), 1);
	ft_printf("todo fue bien :D, y limpiamos!!\n");//
	clean_data_cube(&root_nd);
	return (0);
}
