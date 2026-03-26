/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 19:02:58 by plepercq          #+#    #+#             */
/*   Updated: 2026/03/26 11:48:08 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *lit, size_t len)
{
	int				i;
	unsigned int	j;

	i = 0;
	if (*lit == '\0')
		return ((char *)big);
	while (big[i] != '\0' && i + ft_strlen(lit) - 1 < len)
	{
		if (big[i] == lit[0])
		{
			j = 1;
			while (lit[j] == big[i + j] && lit[j])
				j++;
			if (!lit[j])
				return ((char *)(big + i));
		}
		i++;
	}
	return (0);
}
