/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 14:32:30 by plepercq          #+#    #+#             */
/*   Updated: 2026/03/20 17:41:21 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stdio.h>

void	rotate(t_stack **stack)
{
	t_stack	*first;

	first = stack_first(*stack);
	*stack = first->next;
	first->next->prev = NULL;
	first->next = NULL;
	stack_index(stack);
	stack_add_back(stack, first);
}

void	rrotate(t_stack **stack)
{
	t_stack	*last;

	last = stack_last(*stack);
	last->prev->next = NULL;
	last->prev = NULL;
	stack_add_front(stack, last);
	stack_index(stack);
	*stack = last;
}
