/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 14:44:54 by plepercq          #+#    #+#             */
/*   Updated: 2026/04/01 15:40:46 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_utils.h"

void	sa(t_stacks *stacks)
{
	ft_printf("sa");
	swap(stacks->stack_a);
}

void	sb(t_stacks *stacks)
{
	ft_printf("sb");
	swap(stacks->stack_b);
}

void	ss(t_stacks *stacks)
{
	ft_printf("ss");
	swap(stacks->stack_a);
	swap(stacks->stack_b);
}
