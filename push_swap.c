/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 17:10:56 by plepercq          #+#    #+#             */
/*   Updated: 2026/03/18 19:04:18 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_stack(char **inputs, int len)
{
	int		i;
	int		value;
	t_stack	**stack;
	t_stack	*node;

	i = 0;
	while (i < len)
	{
		value = check_atoi(inputs[i]);
		if (value == NULL)
			return (stack_free(stack_first(node)), NULL);
		node = stack_new(value);
		if (node == NULL)
			return (stack_free())
		prev = node;
		id++;
	}
	while (node->prev != NULL)
		node = node->prev;
	return (node);
}

t_stack	*create_stack_from_str(char *str)
{
	int		i;
	char	**strs;
	t_stack	*stack;

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

int	has_duplicates(t_stack **stack)
{
	t_stack	*node;
	t_stack	*other;

	node = *stack;
	while (node->next != NULL)
	{
		other = node->next;
		while (other != NULL)
		{
			if (node->value == other->value)
				return (1);
			other = other->next;
		}
		node = node->next;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		i;
	t_stack	**a_stack;
	t_stack	**b_stack;

	a_stack = malloc(sizeof(t_stack **));
	b_stack = malloc(sizeof(t_stack **));
	if (!a_stack || !b_stack)
		return (free_stack(a_stack), free_stack(b_stack), 0);
	if (argc == 1 || (argc == 2 && *(argv[1]) == '\0'))
		return (0);
	if (argc == 2)
		*a_stack = create_stack_from_str(argv[1]);
	else
		*a_stack = create_stack(&argv[1], argc - 1);


	i = 0;
	while (i < argc - 1)
	{
		ft_printf("======> %s", argv[i + 1]);
		i++;
	}



	if (*a_stack == NULL)
		return (free_stack(a_stack), free_stack(b_stack), ft_printf("error\n"));
	if (has_duplicates(a_stack))
		return (free_stack(a_stack), free_stack(b_stack), ft_printf("error\n"));
	//sort_algorithm(a_stack, b_stack);
	return (free_stack(a_stack), free_stack(b_stack), 0);
}
