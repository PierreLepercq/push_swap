/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 14:32:33 by plepercq          #+#    #+#             */
/*   Updated: 2026/03/10 18:57:37 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	if (stack == NULL)
		return ;
	first = *stack;
	second = first->next;
	if (second == NULL)
		return ;
	third = second->next;
	first->id = 2;
	first->next = third;
	first->prev = second;
	second->id = 1;
	second->next = first;
	second->prev = NULL;
	*stack = second;
}
