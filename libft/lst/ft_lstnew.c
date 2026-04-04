/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuenca- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 17:58:46 by mcuenca-          #+#    #+#             */
/*   Updated: 2026/04/04 14:57:53 by mcuenca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*newnode;

	newnode = malloc(sizeof(t_list));
	if (!newnode)
		return (NULL);
	newnode->content = content;
	newnode->next = NULL;
	newnode->prev = NULL;
	return (newnode);
}

t_list	*ft_lstcopy(t_list *original)
{
	t_list	*copy;
	t_list	*newnode;
	t_list	*tmp;
	void	*contentdup;

	copy = NULL;
	tmp = original;
	contentdup = NULL;
	while (tmp)
	{
		if (ft_str_what_is((char *)tmp->content) < 5)
			contentdup = (char *)ft_strdup((char *)tmp->content);
		else
			contentdup = (int *)ft_intdup(*(int *)tmp->content);
		if (!contentdup)
			return (NULL);
		newnode = ft_lstnew(contentdup);
		if (!newnode)
			return (NULL);
		ft_lstadd_back(&copy, newnode);
		if (!(ft_lstlast(copy)))
			return (NULL);
		tmp = tmp->next;
	}
	return (copy);
}
