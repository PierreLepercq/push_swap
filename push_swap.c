/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 17:10:56 by plepercq          #+#    #+#             */
/*   Updated: 2026/03/22 16:31:37 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	view_stack(t_stack **stack, const char *label)
{
	t_stack	*node;

	ft_printf("\n>      %s      <\n", label);
	if (*stack == NULL)
		ft_printf("empty\n");
	node = *stack;
	while (node != NULL)
	{
		ft_printf("value[%i] : %i\n", node->id, node->value);
		node = node->next;
	}
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

t_stack	**create_stack(char **inputs, int len)
{
	int		i;
	int		value;
	t_stack	**stack;
	t_stack	*node;

	i = 0;
	stack = malloc(sizeof(t_stack **));
	if (stack == NULL)
		return (NULL);
	*stack = NULL;
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

t_stack	**create_stack_from_str(char *str)
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
	stack = create_stack(strs, i);
	free(strs);
	return (stack);
}

void	sort_algorithm(t_stack **a_stack, t_stack **b_stack)
{
	view_stack(a_stack, "stack A");
	view_stack(b_stack, "stack B");

	push(a_stack, b_stack);
	push(a_stack, b_stack);

	view_stack(a_stack, "stack A");
	view_stack(b_stack, "stack B");

	rotate(b_stack);

	view_stack(a_stack, "stack A");
	view_stack(b_stack, "stack B");

	rrotate(b_stack);

	view_stack(a_stack, "stack A");
	view_stack(b_stack, "stack B");

	swap(b_stack);

	view_stack(a_stack, "stack A");
	view_stack(b_stack, "stack B");

	push(b_stack, a_stack);
	push(b_stack, a_stack);

	view_stack(a_stack, "stack A");
	view_stack(b_stack, "stack B");
}

int	main(int argc, char **argv)
{
	t_stack	**a_stack;
	t_stack	**b_stack;

	a_stack = malloc(sizeof(t_stack **));
	b_stack = malloc(sizeof(t_stack **));
	if (!a_stack || !b_stack)
		return (stack_free(a_stack), stack_free(b_stack), 0);
	if (argc == 1 || (argc == 2 && *(argv[1]) == '\0'))
		return (0);
	if (argc == 2)
		a_stack = create_stack_from_str(argv[1]);
	else
		a_stack = create_stack(&argv[1], argc - 1);
	if (*a_stack == NULL || has_duplicates(a_stack))
	{
		ft_printf("error\n");
		return (stack_free(a_stack), stack_free(b_stack), 0);
	}
	sort_algorithm(a_stack, b_stack);
	return (stack_free(a_stack), stack_free(b_stack), 0);
}
