/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuenca- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 17:08:15 by mcuenca-          #+#    #+#             */
/*   Updated: 2026/03/21 13:27:17 by mcuenca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*void	del(void *content)
{
	if (content)
		free(content);
}

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst)
		return ;
	if (lst->content && del)
	{
		del(lst->content);
		if (lst->prev != NULL)
			lst->prev->next = lst->next;
		if (lst->next != NULL)
			lst->next->prev = lst->prev;
	}
	free(lst);
}*/

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	if (lst->content != NULL)
		del(lst->content);
	free(lst);
}
