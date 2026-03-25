/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuenca- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 12:38:32 by mcuenca-          #+#    #+#             */
/*   Updated: 2025/01/10 13:21:48 by mcuenca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lsthalf(t_list *lst, t_list	*node)
{
	int	i;
	int	size;

	if (!lst || !node)
		return (0);
	i = 0;
	size = ft_lstsize(lst);
	while (lst != node)
	{
		lst = lst->next;
		i++;
	}
	if (i < size / 2)
		return (1);
	return (2);
}

t_list	*ft_lstfindnode(t_list *lst, int find_node)
{
	int	i;

	i = 0;
	while (i < find_node && lst->next)
	{
		i++;
		lst = lst->next;
	}
	if (!(lst->next) && !lst)
		return (write(1, "Node don't found.", 17), ft_lstlast(lst));
	return (lst);
}

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
