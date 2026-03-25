/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 18:31:01 by plepercq          #+#    #+#             */
/*   Updated: 2026/03/25 18:36:04 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// TODO : remove libft

#include "libft.h"
#include "stack.h"
#include <stdio.h>

void	rrotate(t_stack **stack)
{
	*stack = (*stack)->prev;
	stack_index(stack);
}

void	rra(t_stacks *stacks)
{
	ft_printf("> R Rotate A");
	rrotate(stacks->stack_a);
}

void	rrb(t_stacks *stacks)
{
	ft_printf("> R Rotate B");
	rrotate(stacks->stack_b);
}

void	rrr(t_stacks *stacks)
{
	ft_printf("> R Rotate A & B");
	rrotate(stacks->stack_a);
	rrotate(stacks->stack_b);
}
