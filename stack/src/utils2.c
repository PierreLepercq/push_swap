/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 18:36:43 by plepercq          #+#    #+#             */
/*   Updated: 2026/03/22 16:05:45 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	stack_add_front(t_stack **stack, t_stack *new)
{
	if (new == NULL)
		return ;
	if (*stack)
	{
		new->next = *stack;
		(*stack)->prev = new;
	}
	*stack = new;
	stack_index(stack);
}

void	stack_add_back(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (new == NULL)
		return ;
	last = stack_last(*stack);
	if (last != NULL)
	{
		last->next = new;
		new->prev = last;
		new->id = last->id + 1;
	}
	else
		*stack = new;
}

void	stack_free(t_stack **stack)
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
