/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 16:23:03 by plepercq          #+#    #+#             */
/*   Updated: 2026/01/23 17:27:12 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

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

char	**ft_split(char *str, char sep)
{
	char	**strs;

	(void)str;
	(void)sep;
	strs = NULL;
	return (strs);
}

#include <stdio.h>

int	main(int argc, char**argv)
{
	char	*str = "Ceci est un test!";

	(void)argc;
	(void)argv;
	printf("str : %s\n", str);
	printf("split count : %i", split_count(str, ' '));
}

