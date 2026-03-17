/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_unbr_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 18:14:51 by plepercq          #+#    #+#             */
/*   Updated: 2026/03/17 15:35:40 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	_put_unbr_base(unsigned long nb, char *base)
{
	char			cnb;
	int				len;
	unsigned long	base_len;

	base_len = 0;
	while (base[base_len])
		base_len++;
	if (nb >= base_len)
		len = _put_unbr_base(nb / base_len, base);
	else
		len = 0;
	cnb = base[nb % base_len];
	write(1, &cnb, 1);
	return (len + 1);
}

int	w_unbr_base(unsigned long nb, char *base)
{
	if (check_base(base) == 0)
		return (0);
	return (_put_unbr_base(nb, base));
}
