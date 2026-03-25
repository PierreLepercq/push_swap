/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 17:10:56 by plepercq          #+#    #+#             */
/*   Updated: 2026/03/25 16:25:02 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define STR_INT_MAX "2147483647"
#define STR_INT_MIN "-2147483648"

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
	// TODO penser a voir plus si nbr commence par 00000000000001
	if (len > 10)
		return (0);
	if (len == 10 && sign == '+' && ft_strncmp(s + i, STR_INT_MAX, 10) > 0)
		return (0);
	if (len == 10 && sign == '-' && ft_strncmp(s + i, &STR_INT_MIN[1], 10) > 0)
		return (0);
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
	t_stack		**stack_a;
	t_stack		**stack_b;

	if (argc == 1)
		return (ft_printf("error : number arguments\n"), 0);
	stack_a = malloc(sizeof(t_stack *));
	stack_b = malloc(sizeof(t_stack *));
	if (!stack_a || !stack_b)
		return (stack_free(stack_a), stack_free(stack_b), 0);
	if (argc == 2)
		stack_a = init_stack_from_str(stack_a, argv[1]);
	// todo check if error in init stack (pour le momoent la stack est juste egale a null)
	else
		stack_a = init_stack(stack_a, &argv[1], argc - 1);
	if (has_duplicates(stack_a))
	{
		ft_printf("error\n");
		return (stack_free(stack_a), stack_free(stack_b), 0);
	}
	turk_algorithm(stack_a, stack_b);
	return (stack_free(stack_a), stack_free(stack_b), 0);
}
