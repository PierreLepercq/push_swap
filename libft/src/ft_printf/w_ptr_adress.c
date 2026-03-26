/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_ptr_adress.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 18:14:51 by plepercq          #+#    #+#             */
/*   Updated: 2026/03/17 15:35:30 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	w_ptr_adress(unsigned long ptr)
{
	if (ptr == 0)
		return (write(1, "(nil)", 5), 5);
	write(1, "0x", 2);
	return (w_unbr_base(ptr, "0123456789abcdef") + 2);
}
