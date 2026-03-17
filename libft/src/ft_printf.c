/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 18:14:51 by plepercq          #+#    #+#             */
/*   Updated: 2026/03/17 15:35:14 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	write_value(const char *s, va_list args)
{
	if (*s == '%')
		return (w_char('%'));
	if (*s == 'c')
		return (w_char(va_arg(args, int)));
	if (*s == 's')
		return (w_str(va_arg(args, char *)));
	if (*s == 'i' || *s == 'd')
		return (w_nbr_base(va_arg(args, int), "0123456789"));
	if (*s == 'u')
		return (w_unbr_base(va_arg(args, unsigned int), "0123456789"));
	if (*s == 'x')
		return (w_unbr_base(va_arg(args, unsigned int), "0123456789abcdef"));
	if (*s == 'X')
		return (w_unbr_base(va_arg(args, unsigned int), "0123456789ABCDEF"));
	if (*s == 'p')
		return (w_ptr_adress(va_arg(args, unsigned long)));
	return (0);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		len;
	va_list	args;

	if (!s)
		return (0);
	len = 0;
	va_start(args, s);
	while (*s != '\0')
	{
		i = 0;
		while (s[i] != 0 && s[i] != '%')
			i++;
		write(1, s, i);
		s += i;
		len += i;
		if (*s == '%')
		{
			len += write_value(++s, args);
			s++;
		}
	}
	va_end(args);
	return (len);
}
