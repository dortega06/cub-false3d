/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuenca- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 12:17:53 by mcuenca-          #+#    #+#             */
/*   Updated: 2026/04/04 14:41:46 by mcuenca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if ((c >= 32) && (c <= 126))
		return (1);
	else
		return (0);
}

int	ft_str_isprint(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(ft_isprint(str[i])))
			return (0);
		i++;
	}
	return (1);
}

int	ft_str_2ptr_isprint(const char **str_2ptr)
{
	int	j;

	if (!str_2ptr)
		return (0);
	j = 0;
	while (str_2ptr[j])
	{
		if (!ft_str_isprint(str_2ptr[j]))
			return (0);
		j++;
	}
	return (1);
}
