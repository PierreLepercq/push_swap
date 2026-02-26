/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 16:23:03 by plepercq          #+#    #+#             */
/*   Updated: 2026/02/26 18:50:18 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

int	split_count(char *str, char sep)
{
	int	i;
	int	count;

	count = 0;
	while (*str)
	{
		i = 1;
		while (str[i] != sep && str[i])
			i++;
		if (i > 1)
			count++;
		str += i;
	}
	return (count);
}

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

void	del_tab(char **strs, int tab_id)
{
	while (tab_id >= 0)
		free(strs[tab_id]);
	free(strs);
}

char	**ft_split(char *str, char sep)
{
	int		sublen;
	int		tab_id;
	int		tab_size;
	char	*substr;
	char	**strs;

	tab_size = split_count(str, sep);
	strs = malloc(sizeof(char **) * (tab_size + 1));
	if (!strs)
		return (NULL);
	tab_id = 0;
	while (tab_id < tab_size)
	{
		sublen = 0;
		while (*str == sep)
			str++;
		while (str[sublen] != sep && str[sublen] != '\0')
			sublen++;
		substr = ft_substr(str, 0, sublen);
		if (!substr)
			return (del_tab(strs, tab_id), NULL);
		strs[tab_id++] = substr;
		str += sublen;
	}
	strs[tab_id] = NULL;
	return (strs);
}

/*
int	main(int argc, char**argv)
{
	int		id;
	char	*str = "Ceci est un test!";
	char	**strs;

	(void)argc;
	(void)argv;
	
	printf("str : %s\n", str);
	
	strs = ft_split(str, ' ');
	
	//return (1);

	if (!strs)
		return (0);

	id = 0;
	while (strs[id])
	{
		printf("word %i : %s\n", id, strs[id]);
		id++;
	}
}
*/
