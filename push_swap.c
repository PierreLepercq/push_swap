/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 17:10:56 by plepercq          #+#    #+#             */
/*   Updated: 2026/04/01 15:50:56 by plepercq         ###   ########.fr       */
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

t_stack	**init_stack(t_stack **stack, char **inputs, int len)
{
	int		i;
	int		value;
	t_stack	*node;

	i = 0;
	stack_free(stack);
	while (i < len)
	{
		if (check_atoi(inputs[i]) == 0)
			return (stack_free(stack), NULL);
		value = ft_atoi(inputs[i]);
		node = stack_new(value);
		if (node == NULL)
			return (stack_free(stack), NULL);
		stack_add_back(stack, node);
		i++;
	}
	return (stack);
}

t_stack	**init_stack_from_str(t_stack **stack, char *str)
{
	int		i;
	char	**strs;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_strchr(" 0123456789-+", str[i]) == NULL)
			return (NULL);
	}
	strs = ft_split(str, " ");
	if (!strs)
		return (NULL);
	i = 0;
	while (strs[i] != NULL)
		i++;
	init_stack(stack, strs, i);
	free(strs);
	return (stack);
}

int	main(int argc, char **argv)
{
	t_stacks		*stacks;

	if (argc == 1)
		return (ft_printf("error : number arguments\n"), 0);
	stacks = stacks_new();
	if (!stacks)
		return (0);
	if (argc == 2)
		stacks->stack_a = init_stack_from_str(stacks->stack_a, argv[1]);
	// todo check if error in init stack (pour le momoent la stack est juste egale a null)
	else
		stacks->stack_a = init_stack(stacks->stack_a, &argv[1], argc - 1);
	if (has_duplicates(stacks->stack_a))
	{
		ft_printf("error\n");
		return (stacks_free(stacks), 0);
	}
	turk_algorithm(stacks);
	return (stacks_free(stacks), 0);
}
