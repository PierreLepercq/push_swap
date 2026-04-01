/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 14:43:00 by plepercq          #+#    #+#             */
/*   Updated: 2026/04/01 15:41:09 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_utils.h"

void	pa(t_stacks *stacks)
{
	ft_printf("pa");
	push(stacks->stack_b, stacks->stack_a);
}

void	pb(t_stacks *stacks)
{
	ft_printf("pb");
	push(stacks->stack_a, stacks->stack_b);
}