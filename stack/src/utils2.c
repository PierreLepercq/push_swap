/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 18:36:43 by plepercq          #+#    #+#             */
/*   Updated: 2026/03/23 16:21:03 by plepercq         ###   ########.fr       */
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
	if (new == NULL)
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
		*stack = new;
		new->prev = new;
		new->next = new;
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

void	stack_free(t_stack **stack)
{
	t_stack	*node;
	t_stack	*next;

	if (*stack == NULL)
		return ;
	node = (*stack)->next;
	while (node != *stack)
	{
		next = node->next;
		free(node);
		node = next;
	}
	free(node);
}

int	has_duplicates(t_stack **stack)
{
	t_stack	*node;
	t_stack	*other;

	node = *stack;
	while (node->next != *stack)
	{
		other = node->next;
		while (other != *stack)
		{
			if (node->value == other->value)
				return (1);
			other = other->next;
		}
		node = node->next;
	}
	return (0);
}
