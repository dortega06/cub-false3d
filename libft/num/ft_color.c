/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuenca- <mcuenca-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:48:38 by mcuenca-          #+#    #+#             */
/*   Updated: 2026/04/08 18:32:48 by mcuenca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_get_r(int rgba)
{
	return ((rgba >> 24) & 0xFF);
}

int	ft_get_g(int rgba)
{
	return ((rgba >> 16) & 0xFF);
}

int	ft_get_b(int rgba)
{
	return ((rgba >> 8) & 0xFF);
}

int	ft_get_a(int rgba)
{
	return (rgba & 0xFF);
}

int	ft_get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}
