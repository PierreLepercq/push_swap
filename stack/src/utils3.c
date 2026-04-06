/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 00:00:12 by plepercq          #+#    #+#             */
/*   Updated: 2026/04/06 11:02:54 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

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
