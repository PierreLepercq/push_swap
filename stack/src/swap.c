/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 14:32:33 by plepercq          #+#    #+#             */
/*   Updated: 2026/03/26 11:12:15 by plepercq         ###   ########.fr       */
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

void	sa(t_stacks *stacks)
{
	ft_printf("> Swap A");
	swap(stacks->stack_a);
}

void	sb(t_stacks *stacks)
{
	ft_printf("> Swap B");
	swap(stacks->stack_b);
}

void	ss(t_stacks *stacks)
{
	ft_printf("> Swap A & B");
	swap(stacks->stack_a);
	swap(stacks->stack_b);
}
