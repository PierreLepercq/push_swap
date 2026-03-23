/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 17:10:56 by plepercq          #+#    #+#             */
/*   Updated: 2026/03/23 19:35:02 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define STR_INT_MAX "2147483647"
#define STR_INT_MIN	"-2147483648"

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
	int		**values;

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

int	*strs_to_ints(char	**strs, int len)
{
	int		i;
	int		*ints;

	i = 0;
	ints = malloc(sizeof(int) * (len + 1));
	if (ints == NULL)
		return (NULL);
	while (i < len)
	{
		if (check_atoi(strs[i]) == 0)
			return (free(ints), NULL);
		ints[i] = ft_atoi(strs[i]);
		i++;
	}
	ints[i] = NULL;
	return (ints);
}

int	*confo_inputs(char	**inputs, int len)
{
	int		i;
	char	**strs;

	if (len > 1)
		return (strs_to_ints(inputs, len));
	strs = ft_split(inputs, " ");
		if (!strs)
			return (NULL);
		i = 0;
		while (strs[i] != NULL)
			i++;
	}
	else
	{
		strs = inputs;
		i = len;
	}
	
	return (values);
}

t_stack	**init_stack_from_str(char *str)
{
	int		i;
	char	**strs;
	t_stack	**stack;

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
	stack = init_stack(strs, i);
	free(strs);
	return (stack);
}

int	main(int argc, char **argv)
{
	int			*values;
	t_stacks	*stacks;

	if (argc == 1 || (argc == 2 && *(argv[1]) == '\0'))
		return (ft_printf("error : number arguments\n"), 0);
	values = confo_inputs(&argv[1], argc - 1);
	if (!values)
		return (ft_printf("error : confo inputs\n"), 0);


	stacks = create_stacks();
	if (!stacks)
		return (ft_printf("error stacks creation\n"), 0);
	if (argc == 2)
		stacks->stack_a = init_stack_from_str(argv[1]);
	else
		stacks->stack_a = init_stack(&argv[1], argc - 1);
	if (has_duplicates(stacks->stack_a))
	{
		ft_printf("error\n");
		return (stack_free(a_stack), stack_free(b_stack), 0);
	}
	test_algorithm(a_stack, b_stack);
	return (stack_free(a_stack), stack_free(b_stack), 0);
}

t_stacks	*create_stacks(void)
{
	t_stack		**stack_a;
	t_stack		**stack_b;
	t_stacks	*stacks;

	stacks = malloc(sizeof(t_stacks *));
	if (!stacks)
		return (NULL);
	stack_a = malloc(sizeof(t_stack **));
	stack_b = malloc(sizeof(t_stack **));
	if (!stack_a || !stack_b)
	{
		stack_free(stack_a);
		stack_free(stack_b);
		free(stacks);
		return (NULL);
	}
	stacks->stack_a = stack_a;
	stacks->stack_b = stack_b;
	return (stacks);
}
