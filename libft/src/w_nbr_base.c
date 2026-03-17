/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_nbr_base.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 18:14:51 by plepercq          #+#    #+#             */
/*   Updated: 2026/03/17 15:35:22 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	labs(long nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

static int	_put_nbr_base(long nb, char *base)
{
	char	cnb;
	int		len;
	int		base_len;

	base_len = 0;
	while (base[base_len])
		base_len++;
	if (nb <= -base_len || nb >= base_len)
		len = _put_nbr_base(nb / base_len, base);
	else
		len = 0;
	cnb = base[labs(nb % base_len)];
	write(1, &cnb, 1);
	return (len + 1);
}

int	w_nbr_base(long nb, char *base)
{
	int	len;

	len = 0;
	if (check_base(base) == 0)
		return (0);
	if (nb < 0)
	{
		write(1, "-", 1);
		len++;
	}
	return (len + _put_nbr_base(nb, base));
}
