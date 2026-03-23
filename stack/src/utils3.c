/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 18:42:33 by plepercq          #+#    #+#             */
/*   Updated: 2026/03/23 16:11:03 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack	*stack_min(t_stack **stack)
{
	t_stack	*node;
	t_stack	*other;

	if (*stack == NULL)
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

	if (*stack == NULL)
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

void	stack_print(t_stack **stack, const char *label)
{
	t_stack	*node;

	ft_printf("\n>      %s      <\n", label);
	if (*stack == NULL)
		ft_printf("empty\n");
	node = *stack;
	while (node)
	{
		ft_printf("value[%i] : %i\n", node->id, node->value);
		node = node->next;
		if (node == *stack)
			break ;
	}
}
