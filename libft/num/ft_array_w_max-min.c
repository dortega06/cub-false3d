/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_w_max-min.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuenca- <mcuenca-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 21:37:53 by mcuenca-          #+#    #+#             */
/*   Updated: 2025/01/04 21:38:17 by mcuenca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_num_max(int *count)
{
	int	i;
	int	j;
	int	k;
	int	currmax;

	k = 1;
	currmax = count[1];
	while (count[k + 1])
	{
		i = count[k];
		j = count[k + 1];
		if (i > j && i > currmax)
			currmax = i;
		else if (j > i && j > currmax)
			currmax = j;
		k++;
	}
	return (currmax);
}

int	ft_num_min(int *count)
{
	int	i;
	int	j;
	int	k;
	int	currmin;

	k = 1;
	currmin = count[1];
	while (count[k + 1])
	{
		i = count[k];
		j = count[k + 1];
		if (i < j && i < currmin)
			currmin = i;
		else if (j < i && j < currmin)
			currmin = j;
		k++;
	}
	return (currmin);
}
