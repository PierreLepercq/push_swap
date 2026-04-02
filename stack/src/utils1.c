/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 18:11:37 by plepercq          #+#    #+#             */
/*   Updated: 2026/04/02 15:30:06 by plepercq         ###   ########.fr       */
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

int	stack_len(t_stack **stack)
{
	int		i;
	t_stack	*node;

	if (*stack == NULL)
		return (0);
	i = 1;
	node = (*stack)->next;
	while (node != *stack)
	{
		node = node->next;
		i++;
	}
	return (i);
}

int	stask_is_sorted(t_stack	*stack)
{
	t_stack	*min;
	t_stack	*cursor;

	min = stack_min(stack);
	cursor = min;
	while (cursor->next != min)
	{
		if (cursor > cursor->next)
			return (0);
		cursor = cursor->next;
	}
	return (1);
}

void	stack_iter(t_stack **stack, void (*f)(void *))
{
	t_stack	*node;

	if (*stack == NULL)
		return ;
	f(*stack);
	node = (*stack)->next;
	while (node != *stack)
	{
		f(node);
		node = node->next;
	}
}
