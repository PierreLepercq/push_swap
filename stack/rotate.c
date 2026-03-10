/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 14:32:30 by plepercq          #+#    #+#             */
/*   Updated: 2026/03/10 19:16:13 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (*stack == NULL)
		return ;
	first = stack_first(*stack);
	last = stack_last(*stack);
	if (first == last)
		return ;
	last->next = first;
	first->next->prev = NULL;
	first->next = NULL;
}

void	rrotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (*stack == NULL)
		return ;
	first = stack_first(*stack);
	last = stack_last(*stack);
	if (first == last)
		return ;
	first->prev = last;
	last->prev->next = NULL;
	last->prev = NULL;
}
