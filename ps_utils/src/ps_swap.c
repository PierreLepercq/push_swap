/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 14:44:54 by plepercq          #+#    #+#             */
/*   Updated: 2026/04/05 23:20:36 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_utils.h"

void	sa(t_stacks *stacks)
{
	ft_printf("sa\n");
	swap(stacks->a);
}

void	sb(t_stacks *stacks)
{
	ft_printf("sb\n");
	swap(stacks->b);
}

void	ss(t_stacks *stacks)
{
	ft_printf("ss\n");
	swap(stacks->a);
	swap(stacks->b);
}
