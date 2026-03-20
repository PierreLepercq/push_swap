/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 14:38:18 by plepercq          #+#    #+#             */
/*   Updated: 2026/03/20 15:10:52 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <limits.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i + 1 < n && s1[i])
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			break ;
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	check_atoi(const char *s)
{
	int		i;
	size_t	len;
	char	sign;

	i = 0;
	len = 0;
	sign = '+';
	while (s[i] == ' ' || (s[i] >= '\t' && s[i] <= '\r'))
		i++;
	if (s[i] == '+' || s[i] == '-')
		sign = s[i++];
	while (s[i + len] != '\0')
	{
		if (s[i + len] < '0' && s[i] > '9')
			return (0);
		len++;
	}
	if (len > 10)
		return (0);
	if (len == 10 && sign == '+' && ft_strncmp(s + i, "2147483647", 10) > 0)
		return (0);
	if (len == 10 && sign == '-' && ft_strncmp(s + i, "2147483648", 10) > 0)
		return (0);
	return (1);
}

int main()
{
    printf("MAX : %i | MIN : %i", INT_MAX, INT_MIN);
    printf("\ncheck_atoi : %i", check_atoi("2147483648"));
}
