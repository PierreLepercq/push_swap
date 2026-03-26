/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:40:09 by plepercq          #+#    #+#             */
/*   Updated: 2025/11/16 18:49:38 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	int		index;

	if (dest == NULL && src == NULL)
		return (NULL);
	i = 0;
	while (++i <= n)
	{
		if (dest < src)
			index = i - 1;
		else
			index = n - i;
		ft_memcpy(dest + index, src + index, 1);
	}
	return (dest);
}
