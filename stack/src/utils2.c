/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 18:36:43 by plepercq          #+#    #+#             */
/*   Updated: 2026/03/17 16:26:09 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	stack_add_front(t_stack **stack, t_stack *new)
{
	if (!new)
		return ;
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
