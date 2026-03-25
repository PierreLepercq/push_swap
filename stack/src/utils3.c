/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 18:42:33 by plepercq          #+#    #+#             */
/*   Updated: 2026/03/25 18:44:12 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

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
