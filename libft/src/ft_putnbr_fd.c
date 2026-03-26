/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 17:18:44 by plepercq          #+#    #+#             */
/*   Updated: 2025/11/18 17:32:34 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	writenbr(int n, int fd)
{
	char	cn;

	if (n < -9 || n > 9)
		writenbr(n / 10, fd);
	if (n < 0)
		cn = '0' - (n % 10);
	else
		cn = '0' + (n % 10);
	write(fd, &cn, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		write(fd, "-", 1);
		writenbr(n, fd);
	}
	else
		writenbr(n, fd);
}
