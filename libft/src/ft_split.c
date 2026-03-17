/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 16:23:03 by plepercq          #+#    #+#             */
/*   Updated: 2026/03/17 14:56:12 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	split_count(char *str, char *charset)
{
	int	i;
	int	count;

	count = 0;
	while (*str)
	{
		i = 1;
		while (ft_strchr(charset, str[i]) == NULL && str[i])
			i++;
		if (i > 1)
			count++;
		str += i;
	}
	return (count);
}

void	del_tab(char **strs, int tab_id)
{
	while (tab_id >= 0)
		free(strs[tab_id]);
	free(strs);
}

char	**ft_split(char *str, char *charset)
{
	int		len;
	int		tab_id;
	int		tab_size;
	char	*substr;
	char	**strs;

	tab_size = split_count(str, charset);
	strs = malloc(sizeof(char **) * (tab_size + 1));
	if (!strs)
		return (NULL);
	tab_id = 0;
	while (tab_id < tab_size)
	{
		while (ft_strchr(charset, *str) != NULL)
			str++;
		len = 0;
		while (ft_strchr(charset, str[len]) == NULL && str[len] != '\0')
			len++;
		substr = ft_substr(str, 0, len);
		if (!substr)
			return (del_tab(strs, tab_id), NULL);
		strs[tab_id++] = substr;
		str += len;
	}
	return (strs[tab_id] = NULL, strs);
}
/*
#include <stdio.h>

int	main(int argc, char**argv)
{
	int		id;
	char	*str = "Ceci est un test!";
	char	*charset = " ";
	char	**strs;

	if (argc > 1)
		str = argv[1];

	if (argc > 2)
		charset = argv[2];

	printf("str : %s\n", str);
	printf("charset : %s\n", charset);

	strs = ft_split(str, charset);

	if (!strs)
		return (0);

	id = 0;
	while (strs[id])
	{
		printf("[%i] %s\n", id, strs[id]);
		id++;
	}
}*/