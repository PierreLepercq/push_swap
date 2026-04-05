/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 14:43:00 by plepercq          #+#    #+#             */
/*   Updated: 2026/04/05 23:20:22 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_utils.h"

void	pa(t_stacks *stacks)
{
	ft_printf("pa\n");
	push(stacks->b, stacks->a);
}

void	pb(t_stacks *stacks)
{
	ft_printf("pb\n");
	push(stacks->a, stacks->b);
}
