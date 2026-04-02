/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuenca- <mcuenca-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 17:44:59 by mcuenca-          #+#    #+#             */
/*   Updated: 2026/04/02 10:55:48 by mcuenca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	no_ptr_or_size_zero(void *ptr, size_t size, void **newmem)
{
	if (ptr && size == 0)
		return (ft_free(ptr), OK);
	else if (!ptr && size > 0)
	{
		*newmem = malloc(size);
		if (!*newmem)
			return (MALLOC);
		return (OK);
	}
	return (ERR);
}

void	*ft_realloc(void *ptr, size_t size)
{
	int		return_val;
	size_t	len;
	void	*newmem;

	newmem = NULL;
	return_val = no_ptr_or_size_zero(ptr, size, &newmem);
	if (return_val == OK)
		return (newmem);
	else if (return_val == MALLOC)
		return (ft_free(ptr), NULL);
	len = ft_strlen(ptr);
	if (len > size || len == size)
		return (ptr);
	if (len < size)
	{
		newmem = malloc(size);
		if (!newmem)
			return (NULL);
		ft_memcpy(newmem, ptr, len);
		ft_free(ptr);
		ptr = newmem;
	}
	return (newmem);
}
