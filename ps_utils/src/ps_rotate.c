/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 14:45:02 by plepercq          #+#    #+#             */
/*   Updated: 2026/04/01 15:40:07 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_utils.h"

void	ra(t_stacks *stacks)
{
	ft_printf("ra");
	rotate(stacks->stack_a);
}

void	rb(t_stacks *stacks)
{
	ft_printf("rb");
	rotate(stacks->stack_b);
}

void	rr(t_stacks *stacks)
{
	ft_printf("rr");
	rotate(stacks->stack_a);
	rotate(stacks->stack_b);
}
