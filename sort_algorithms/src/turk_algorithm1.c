/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algorithm1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 15:21:29 by plepercq          #+#    #+#             */
/*   Updated: 2026/04/06 15:05:52 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_algorithms.h"

int	nrot(t_stack *node)
{
	return (node->id);
}

int	nrrot(t_stack *node)
{
	return (stack_len(&node) - node->id);
}

void	sort_three_a(t_stacks *stacks)
{
	t_stack	*max;

	max = stack_max(stacks->a);
	if (max->id == 0)
		ra(stacks);
	if (max->id == 1)
		rra(stacks);
	if ((*(stacks->a))->value > (*(stacks->a))->next->value)
		sa(stacks);
}

t_stack	*get_closest_bigger(t_stack **stack, t_stack *node)
{
	t_stack	*cursor;
	t_stack	*closest;

	if (!stack || !*stack || !node)
		return (NULL);
	closest = stack_max(stack);
	if (closest->value < node->value)
		return (closest);
	cursor = *stack;
	while (cursor->next != *stack)
	{
		if (cursor->value < closest->value && cursor->value > node->value)
			closest = cursor;
		cursor = cursor->next;
	}
	if (cursor->value < closest->value && cursor->value > node->value)
		closest = cursor;
	if (closest == node)
		closest = NULL;
	return (closest);
}
