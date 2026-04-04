/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algorithm1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 15:21:29 by plepercq          #+#    #+#             */
/*   Updated: 2026/04/04 15:43:14 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_algorithms.h"

int	nrot(t_stack *node)
{
	return (node->id);
}

int	nrrot(t_stack *node)
{
	return (stack_len(node) - node->id);
}

void	sort_three(t_stack **stack)
{
	t_stack	*max;

	max = stack_max(stack);
	if (max->id == 0)
		rotate(stack);
	if (max->id == 1)
		rrotate(stack);
	if ((*stack)->value > (*stack)->next->value)
		swap(stack);
}

t_stack	*get_closest_smaller(t_stack *stack, t_stack *node)
{
	t_stack	*cursor;
	t_stack	*closest;

	closest = stack_min(stack);
	cursor = stack;
	while (cursor->next != stack)
	{
		if (cursor->value > closest->value && cursor->value < node->value)
			closest = cursor;
		cursor = cursor->next;
	}
	if (cursor->value > node->value && cursor->value < node->value)
		closest = cursor;
	if (closest == node)
		closest = NULL;
	return (closest);
}
