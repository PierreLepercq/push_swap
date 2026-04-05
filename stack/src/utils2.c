/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 18:36:43 by plepercq          #+#    #+#             */
/*   Updated: 2026/04/05 22:05:39 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	stack_index(t_stack **stack)
{
	int		id;
	t_stack	*node;

	if (*stack == NULL)
		return ;
	id = 0;
	node = *stack;
	node->id = id++;
	node = node->next;
	while (node != *stack)
	{
		node->id = id++;
		node = node->next;
	}
}

void	stack_add_front(t_stack **stack, t_stack *new)
{
	if (stack == NULL || new == NULL)
		return ;
	if (*stack != NULL)
	{
		new->next = *stack;
		new->prev = (*stack)->prev;
		(*stack)->prev->next = new;
		(*stack)->prev = new;
	}
	else
	{
		new->next = new;
		new->prev = new;
	}
	*stack = new;
	stack_index(stack);
}

void	stack_add_back(t_stack **stack, t_stack *new)
{
	if (new == NULL)
		return ;
	if (*stack == NULL)
	{
		new->prev = new;
		new->next = new;
		*stack = new;
	}
	else
	{
		new->next = *stack;
		new->prev = (*stack)->prev;
		(*stack)->prev->next = new;
		(*stack)->prev = new;
	}
	stack_index(stack);
}

t_stack	*stack_min(t_stack **stack)
{
	t_stack	*node;
	t_stack	*other;

	if (stack == NULL)
		return (NULL);
	node = *stack;
	other = node->next;
	while (other != *stack)
	{
		if (other->value < node->value)
			node = other;
		other = other->next;
	}
	return (node);
}

t_stack	*stack_max(t_stack **stack)
{
	t_stack	*node;
	t_stack	*other;

	if (stack == NULL)
		return (NULL);
	node = *stack;
	other = node->next;
	while (other != *stack)
	{
		if (other->value > node->value)
			node = other;
		other = other->next;
	}
	return (node);
}
