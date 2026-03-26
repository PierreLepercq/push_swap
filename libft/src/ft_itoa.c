/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:31:58 by plepercq          #+#    #+#             */
/*   Updated: 2025/11/18 17:30:37 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	intchrlen(int n)
{
	int	len;

	len = 1;
	if (n < 0)
		len++;
	while (n / 10)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*fillnbralpha(char *dest, int n)
{
	char	*ptr;

	if (n < -9 || n > 9)
		ptr = fillnbralpha(dest, n / 10);
	else
		ptr = dest;
	if (n < 0)
		*ptr = '0' - (n % 10);
	else
		*ptr = '0' + (n % 10);
	*(ptr + 1) = '\0';
	return (ptr + 1);
}

char	*ft_itoa(int n)
{
	char	*nbralpha;

	nbralpha = malloc(sizeof(char) * (intchrlen(n) + 1));
	if (!nbralpha)
		return (NULL);
	if (n < 0)
	{
		nbralpha[0] = '-';
		fillnbralpha(nbralpha + 1, n);
	}
	else
		fillnbralpha(nbralpha, n);
	return (nbralpha);
}
