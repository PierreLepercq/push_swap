/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 14:32:30 by plepercq          #+#    #+#             */
/*   Updated: 2026/03/26 11:12:04 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	rotate(t_stack **stack)
{
	*stack = (*stack)->next;
	stack_index(stack);
}

void	ra(t_stacks *stacks)
{
	ft_printf("> Rotate A");
	rotate(stacks->stack_a);
}

void	rb(t_stacks *stacks)
{
	ft_printf("> Rotate B");
	rotate(stacks->stack_b);
}

void	rr(t_stacks *stacks)
{
	ft_printf("> Rotate A & B");
	rotate(stacks->stack_a);
	rotate(stacks->stack_b);
}
