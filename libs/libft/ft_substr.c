/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 16:52:20 by plepercq          #+#    #+#             */
/*   Updated: 2026/03/05 17:02:53 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *str, int start, int len)
{
	int		strlen;
	int		substrlen;
	char	*substr;

	if (!str)
		return (NULL);
	strlen = 0;
	while (str[strlen] != '\0')
		strlen++;
	substrlen = 0;
	if (start < strlen)
		substrlen = 0;
	else if (strlen - start < len)
		substrlen = strlen - start;
	substr = malloc(sizeof(char) * (substrlen + 1));
	if (!substr)
		return (NULL);
	strlen = 0;
	while (strlen < len)
	{
		substr[strlen] = str[start + strlen];
		strlen++;
	}
	substr[strlen] = '\0';
	return (substr);
}