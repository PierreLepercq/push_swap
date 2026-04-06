/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 19:59:58 by plepercq          #+#    #+#             */
/*   Updated: 2026/04/06 19:20:00 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *str, unsigned int start, size_t len)
{
	int		sublen;
	char	*substr;

	if (ft_strlen(str) < start)
		sublen = 0;
	else
		sublen = ft_strlen(str) - start;
	if (len < (size_t)sublen)
		sublen = len;
	substr = malloc(sizeof(char) * (sublen + 1));
	if (!substr)
		return (0);
	if (sublen == 0)
		*substr = '\0';
	else
		ft_strlcpy(substr, str + start, sublen + 1);
	return (substr);
}
