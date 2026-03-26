/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 19:02:34 by plepercq          #+#    #+#             */
/*   Updated: 2025/11/16 18:46:22 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*c_ptr;

	i = 0;
	c_ptr = (unsigned char *)s;
	while (i < n)
	{
		if ((unsigned char)c == c_ptr[i])
			return (c_ptr + i);
		i++;
	}
	return (NULL);
}
