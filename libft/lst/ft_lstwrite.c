/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstwrite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuenca- <mcuenca-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 21:14:30 by mcuenca-          #+#    #+#             */
/*   Updated: 2025/01/06 19:40:21 by mcuenca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

void	ft_lstwrite_num(t_list *lst)
{
	int	*check;

	if (!lst)
	{
		ft_printf("NULL\n");
		return ;
	}
	while (lst != NULL)
	{
		if (!(lst->content))
		{
			ft_printf("void -> ");
			lst = lst->next;
		}
		else
		{
			check = (int *)lst->content;
			ft_printf("%i", *check);
			if (lst->next != NULL)
				ft_printf(" -> ");
			lst = lst->next;
		}
	}
	write(1, "\n", 1);
}

void	ft_lstwrite_str(t_list *lst)
{
	int	*check;

	if (!lst)
	{
		ft_printf("NULL\n");
		return ;
	}
	while (lst != NULL)
	{
		if (!(lst->content))
		{
			ft_printf("void -> ");
			lst = lst->next;
		}
		else
		{
			check = (int *)lst->content;
			ft_printf("%s", *check);
			if (lst->next != NULL)
				ft_printf(" -> ");
			lst = lst->next;
		}
	}
	write(1, "\n", 1);
}
