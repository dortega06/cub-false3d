/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuenca- <mcuenca-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 17:16:05 by mcuenca-          #+#    #+#             */
/*   Updated: 2026/05/09 16:53:32 by mcuenca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"
#include "mlx.h"
#include "cube3d.h"

int	cube_instructions(void)
{
	ft_printf("To run the program correctly, you must provide an argument.\n"
		"It must have a .cub extension.\n"
		"Lines 0 to 3 must define textures with a valid path and extension.\n");
	ft_printf("Lines 5 and 6 must define the floor"
		"and ceiling colors, respectively.\n");
	ft_printf("The map must contain only one player position and "
		"must be closed (edges surrounded by '1').\n\n");
	ft_printf("Example:\n"
		"NO textures/North.xpm\n"
		"SO textures/South.xpm\n"
		"WE textures/West.xpm\n"
		"EA textures/East.xpm\n"
		"\n"
		"F 220,100,0\n"
		"C 225,30,0\n"
		"\n"
		"11111\n"
		"10N01\n"
		"11111\n");
	return (1);
}

void	init_data_parse(t_cube *root_nd)
{
	root_nd->fd = -1;
	root_nd->file = NULL;
}

int	main(int argc, char **argv)
{
	t_cube	root_nd;

	if (argc != 2)
		return (cube_instructions());
	ft_memset(&root_nd, 0, sizeof(t_cube));
	init_data_parse(&root_nd);
	if (!parse_cub(argv[1], &root_nd))
		return (clean_data_cube(&root_nd), 1);
	execute(&root_nd);/*Could something work wrong?
						YES: put ft in if condition
						NO: do nothing*/
	clean_data_cube(&root_nd);
	ft_printf("All works correct and clean :D!\n");
	return (0);
}
