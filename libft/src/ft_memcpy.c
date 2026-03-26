/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 12:48:37 by plepercq          #+#    #+#             */
/*   Updated: 2025/11/16 18:48:48 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t siz)
{
	size_t	i;
	char	*c_src;
	char	*c_dst;

	i = 0;
	c_src = (char *)src;
	c_dst = (char *)dst;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (i < siz)
	{
		c_dst[i] = c_src[i];
		i++;
	}
	return (dst);
}
