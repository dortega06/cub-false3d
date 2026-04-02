/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extension.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuenca- <mcuenca-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 19:31:41 by mcuenca-          #+#    #+#             */
/*   Updated: 2026/04/02 19:12:08 by mcuenca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"
#include "cube3d.h"

int	file_name_len(char *file)
{
	int		len;
	char	*slash;

	slash = ft_strrchr(file, '/') + 1;
	len = ft_strlen(slash);
	return (len);
}
t_bool	extension(char *file, char *flag, t_cube *root_nd)
{
	int		file_len;
	t_bool	is_valid;

	is_valid = FALSE;
	file_len = file_name_len(file);
	if (file_len < 5)
		return (ft_printf("Impossible len.\n"), FALSE);
	else
	{
		if (ft_strcmp(flag, "cub") == 0)
			is_valid = check_cub_extension(file, root_nd);
		/*else if (ft_strcmp(flag, "xpm"))
			check_xpm(file, root_nd);*/
		if (!is_valid)
			return (clean_data_cube(root_nd), FALSE);
	}
	return (TRUE);
}
