/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_str.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 18:14:51 by plepercq          #+#    #+#             */
/*   Updated: 2026/03/17 15:35:36 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	w_str(char *str)
{
	int	len;

	if (str == NULL)
		return (write(1, "(null)", 6), 6);
	len = 0;
	while (str[len] != '\0')
		len++;
	if (len != 0)
		write(1, str, len);
	return (len);
}
