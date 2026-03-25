/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuenca- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 11:55:07 by mcuenca-          #+#    #+#             */
/*   Updated: 2024/12/16 12:23:34 by mcuenca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}

int	ft_str_isalpha(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(ft_isalpha(str[i])))
			return (0);
		i++;
	}
	return (1);
}
