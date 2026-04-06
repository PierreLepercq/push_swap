/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 14:50:22 by plepercq          #+#    #+#             */
/*   Updated: 2026/04/06 12:10:22 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	splitcount(const char *s, char sep)
{
	int	i;
	int	count;

	count = 0;
	while (*s)
	{
		i = 1;
		while (s[i] != sep && s[i])
			i++;
		if (i > 1)
			count++;
		s += i;
	}
	if (i > 1)
		count++;
	return (count);
}

int	substrlen(const char *s, char sep)
{
	int	sublen;

	sublen = 0;
	while (s[sublen] != sep && s[sublen] != '\0')
		sublen++;
	return (sublen);
}

void	*freestrs(char **tab, size_t id)
{
	unsigned int	i;

	i = 0;
	while (i < id)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

char	**ft_split(char const *str, char sep)
{
	int		i;
	int		sublen;
	int		tabsize;
	char	*substr;
	char	**strs;

	tabsize = splitcount(str, sep);
	strs = malloc(sizeof(char *) * (tabsize + 1));
	if (!strs)
		return (0);
	i = 0;
	while (i < tabsize)
	{
		while (*str == sep)
			str++;
		sublen = substrlen(str, sep);
		substr = ft_substr(str, 0, sublen);
		if (!substr)
			return (freestrs(strs, i));
		strs[i++] = substr;
		str += sublen;
	}
	strs[i] = NULL;
	return (strs);
}
