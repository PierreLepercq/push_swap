/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 17:10:56 by plepercq          #+#    #+#             */
/*   Updated: 2026/03/17 19:09:37 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_stack_node(int id, int value, t_stack *prev)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->id = id;
	new->value = value;
	new->prev = prev;
	if (prev != NULL)
		prev->next = new;
	return (new);
}

void	free_stack(t_stack **stack)
{
	t_stack	*node;
	t_stack	*next;

	if (stack == NULL || *stack == NULL)
		return ;
	node = *stack;
	while (node->next != NULL)
	{
		next = node->next;
		free(node);
		node = next;
	}
}

t_stack	*init_stack(char **inputs, int len)
{
	int		id;
	int		i;
	int		value;
	t_stack	*node;
	t_stack	*prev;

	id = 0;
	node = NULL;
	prev = NULL;
	while (id < len)
	{
		i = 0;
		while ((inputs[id])[i] != '\0')
		{
			if (ft_strchr("0123456789-+", inputs[id][i++]) == NULL)
				return (free_stack(&prev), NULL);
		}
		value = ft_atoi(inputs[id]);
		node = new_stack_node(id, value, prev);
		prev = node;
		id++;
	}
	while (node->prev != NULL)
		node = node->prev;
	return (node);
}

t_stack	*init_stack_from_str(char *str)
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
		while (other->next != NULL)
		{
			if (node->value == other->value)
			{
				ft_printf("=> %i", node->value);
				return (1);
			}
			other = other->next;
		}
		node = node->next;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	**a_stack;
	t_stack	**b_stack;

	a_stack = malloc(sizeof(t_stack **));
	b_stack = malloc(sizeof(t_stack **));
	if (!a_stack || !b_stack)
		return (free_stack(a_stack), free_stack(b_stack), 0);
	if (argc == 1 || (argc == 2 && *(argv[1]) == '\0'))
		return (0);
	if (argc == 2)
		*a_stack = init_stack_from_str(argv[1]);
	else
		*a_stack = init_stack(argv + 1, argc - 1);
	if (*a_stack == NULL)
		return (free_stack(a_stack), free_stack(b_stack), ft_printf("error\n"));
	ft_printf("result duplicate : %i", has_duplicates(a_stack));
	//if (has_duplicates(a_stack))
	//	return (free_stack(a_stack), free_stack(b_stack), ft_printf("error\n"));
	//sort_algorithm(a_stack, b_stack);
	return (free_stack(a_stack), free_stack(b_stack), 0);
}
