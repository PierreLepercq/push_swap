/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 15:57:32 by plepercq          #+#    #+#             */
/*   Updated: 2026/04/05 23:39:06 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_atoi(const char *s)
{
	int		i;
	long	nbr;
	int		sign;

	i = 0;
	nbr = 0;
	sign = 1;
	while (s[i] == ' ' || (s[i] >= '\t' && s[i] <= '\r'))
		i++;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i++] == '-')
			sign *= -1;
	}
	while (s[i] != '\0')
	{
		if (ft_strchr("0123456789", s[i]) == NULL)
			return (0);
		nbr = nbr * 10 + sign * (s[i++] - '0');
		if (nbr < INT_MIN || nbr > INT_MAX)
			return (0);
	}
	return (1);
}

int	*strs_to_ints(char **strs, int len)
{
	int	i;
	int	*ints;

	i = 0;
	ints = malloc(sizeof(int) * (len));
	if (ints == NULL)
		return (NULL);
	while (i < len)
	{
		if (check_atoi(strs[i]) == 0)
			return (free(ints), NULL);
		ints[i] = ft_atoi(strs[i]);
		i++;
	}
	return (ints);
}

int	*confo_inputs(char **inputs, int *len)
{
	int		i;
	int		*values;
	char	**strs;

	if (*len > 1)
		values = strs_to_ints(inputs, *len);
	else
	{
		strs = ft_split(*inputs, " ");
		if (!strs)
			return (NULL);
		i = 0;
		while (strs[i] != NULL)
			i++;
		values = strs_to_ints(strs, i);
		while (i > 0)
			free(strs[i--]);
		free(strs);
		*len = i;
	}
	return (values);
}

bool	has_duplicates(int *values, int len)
{
	int	i;
	int	j;

	if (!values)
		return (false);
	i = 0;
	while (i < len)
	{
		j = 1;
		while (i + j < len)
		{
			if (values[i] == values[i + j])
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

int	main(int argc, char **argv)
{
	//int			i;
	int			len;
	int			*values;
	t_stacks	*stacks;

	if (argc == 1)
		return (0);
	len = argc - 1;
	values = confo_inputs(&argv[1], &len);
	if (values == NULL)
		return (ft_printf("Error\n"), 0);
	if (has_duplicates(values, len))
		return (free(values), ft_printf("Error\n"), 0);
	stacks = init_stacks(values, len);
	if (!stacks)
		return (free(values), ft_printf("Error\n"), 0);

	//i = 0;
	//while (i < len)
	//{
	//	ft_printf("\nnbr : %i", values[i]);
	//	i++;
	//}

	free(values);
	turk_algorithm(stacks);
	return (stacks_free(stacks), 0);
}
