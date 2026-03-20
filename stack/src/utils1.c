/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 18:11:37 by plepercq          #+#    #+#             */
/*   Updated: 2026/03/20 15:32:01 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack	*stack_new(int value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->id = 0;
	new->value = value;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_stack	*stack_first(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->prev)
		stack = stack->prev;
	return (stack);
}

t_stack	*stack_last(t_stack *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	stack_iter(t_stack **stack, void (*f)(void *))
{
	t_stack	*node;

	if (*stack == NULL)
		return ;
	node = *stack;
	while (node != NULL)
	{
		f(node);
		node = node->next;
	}
}

void	stack_index(t_stack **stack)
{
	int		id;
	t_stack	*node;

	if (*stack == NULL)
		return ;
	id = 0;
	node = *stack;
	while (node != NULL)
	{
		node->id = id++;
		node = node->next;
	}
}
