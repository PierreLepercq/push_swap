/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 18:36:43 by plepercq          #+#    #+#             */
/*   Updated: 2026/03/18 16:02:59 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	stack_add_front(t_stack **stack, t_stack *new)
{
	if (new == NULL)
		return ;
	if (*stack == NULL)
		*stack = new;
	new->next = *stack;
	if (*stack)
		(*stack)->prev = new;
	*stack = new;
	stack_index(*stack);
}

void	stack_add_back(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	last = stack_last(*stack);
	last->next = new;
	new->prev = last;
	new->id = new->prev->id + 1;
}

void	free_stack(t_stack **stack)
{
	t_stack	*node;
	t_stack	*next;

	if (*stack == NULL)
		return ;
	node = *stack;
	while (node != NULL)
	{
		next = node->next;
		free(node);
		node = next;
	}
}
