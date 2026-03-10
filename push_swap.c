/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 17:10:56 by plepercq          #+#    #+#             */
/*   Updated: 2026/03/10 18:12:33 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*init_stack(char **inputs, int len)
{
	int				id;
	int				i;
	int				value;
	t_stack_node	*node;
	t_stack_node	*prev_node;

	id = 0;
	prev_node = NULL;
	while (id < len)
	{
		i = 0;
		while (inputs[id][i] != NULL)
		{
			if (ft_strchr(" 0123456789-+", inputs[id][i++]) == NULL)
				return (delete_stack(node), NULL);
		}
		node = new_stack_node(id, inputs[id], prev_node);
		prev_node = node;
		id++;
	}
	while (prev_node->prev)
		prev_node = prev_node->prev;
	return (prev_node);
}

t_stack_node	*init_stack_from_str(char *str)
{
	int				i;
	char			**strs;
	t_stack_node	*stack;

	i = 0;
	while (str[i] != NULL)
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
	t_stack_node *a_stack;
	t_stack_node *b_stack;

	// Initialize stacks
	a_stack = NULL;
	b_stack = NULL;

	// Handle no inputs
	if (argc == 1 || (argc == 2 && argv[1] == ""))
		return ;

	// Init stack a
	if (argc == 2)
		a_stack = init_stack_from_str(argv[1]);
	else
		a_stack = init_stack(argv + 1, argc - 1);
	if (a_stack == NULL)
		return (write(1, "error", 5));
}