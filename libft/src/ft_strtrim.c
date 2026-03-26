/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:05:16 by plepercq          #+#    #+#             */
/*   Updated: 2025/11/19 13:56:41 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	strtrimlen(char const *s1, char const *set)
{
	int	i;
	int	len;

	len = ft_strlen(s1);
	i = 0;
	while (ft_strchr(set, s1[i++]))
		len--;
	i = 0;
	while (ft_strchr(set, s1[ft_strlen(s1) - 1 - i++]))
		len--;
	if (len < 0)
		return (0);
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	i;
	size_t			s2len;
	char			*s2;

	s2len = strtrimlen(s1, set);
	s2 = malloc(sizeof(char) * (s2len + 1));
	if (!s2)
		return (NULL);
	while (ft_strchr(set, s1[0]))
		s1++;
	i = 0;
	while (i < s2len)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
