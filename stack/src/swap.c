/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 14:32:33 by plepercq          #+#    #+#             */
/*   Updated: 2026/04/01 14:47:19 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (*stack == NULL)
		return ;
	first = *stack;
	second = first->next;
	if (second == first)
		return ;
	first->prev->next = second;
	second->prev = first->prev;
	first->next = second->next;
	second->next->prev = first;
	second->next = first;
	first->prev = second;
	second->id = 0;
	first->id = 1;
	*stack = second;
}
