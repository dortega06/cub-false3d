/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuenca- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 12:04:24 by mcuenca-          #+#    #+#             */
/*   Updated: 2025/01/06 20:48:42 by mcuenca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current;
	t_list	*next_node;

	if (!lst || !*lst)
		return ;
	current = *lst;
	while (current != NULL)
	{
		next_node = current->next;
		ft_lstdelone(current, *del);
		current = next_node;
	}
	*lst = NULL;
}
