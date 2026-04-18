/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuenca- <mcuenca-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 15:04:02 by mcuenca-          #+#    #+#             */
/*   Updated: 2026/04/16 14:46:03 by mcuenca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isbreakline(char	*s)
{
	if (s && (s[0] == '\n'))
		return (1);
	return (0);
}

void	ft_jump_space(const char *str, int *i)
{
	while (str[*i] && (str[*i] == 32 || (str[*i] >= 9 && str[*i] <= 13)))
		(*i)++;
}

int	ft_isspace(int c)
{
	if (c && (c == ' '
			|| c == '\t'
			|| c == '\n'
			|| c == '\v'
			|| c == '\f'
			|| c == '\r'))
		return (1);
	return (0);
}
