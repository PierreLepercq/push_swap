/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 14:43:00 by plepercq          #+#    #+#             */
/*   Updated: 2026/04/04 14:33:30 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_utils.h"

void	pa(t_stacks *stacks)
{
	ft_printf("pa");
	push(stacks->b, stacks->a);
}

void	pb(t_stacks *stacks)
{
	ft_printf("pb");
	push(stacks->a, stacks->b);
}