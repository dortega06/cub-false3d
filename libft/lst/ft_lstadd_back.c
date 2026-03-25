/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuenca- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 15:50:09 by mcuenca-          #+#    #+#             */
/*   Updated: 2024/12/13 15:08:35 by mcuenca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*keepit;

	if (!lst || !*lst)
		*lst = new;
	else
	{
		keepit = ft_lstlast(*lst);
		keepit->next = new;
		new->prev = keepit;
	}
}
