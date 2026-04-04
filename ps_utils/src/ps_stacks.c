/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stacks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 15:37:46 by plepercq          #+#    #+#             */
/*   Updated: 2026/04/04 16:28:38 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_utils.h"

t_stacks	*stacks_new(void)
{
	t_stack		**a;
	t_stack		**b;
	t_stacks	*stacks;

	stacks = malloc(sizeof(t_stacks *));
	if (!stacks)
		return (NULL);
	a = malloc(sizeof(t_stack **));
	b = malloc(sizeof(t_stack **));
	if (!a || !b)
	{
		stack_free(a);
		stack_free(b);
		free(stacks);
		return (NULL);
	}
	stacks->a = a;
	stacks->b = b;
	return (stacks);
}

void	stacks_free(t_stacks **stacks)
{
	stack_free((*stacks)->a);
	stack_free((*stacks)->b);
	stacks = NULL;
	free(stacks);
}

t_stacks	*init_stacks(int *values)
{
	int			i;
	t_stack		*node;
	t_stacks	*stacks;

	stacks = stacks_new();
	if (!stacks)
		return (NULL);
	i = 0;
	while (values[i] != NULL)
	{
		node = stack_new(values[i]);
		if (node == NULL)
			return (stacks_free(stacks), NULL);
		stack_add_back(stacks->a, node);
		i++;
	}
	return (stacks);
}
