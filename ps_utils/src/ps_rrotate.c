/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rrotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 14:44:59 by plepercq          #+#    #+#             */
/*   Updated: 2026/04/05 23:20:29 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_utils.h"

void	rra(t_stacks *stacks)
{
	ft_printf("rra\n");
	rrotate(stacks->a);
}

void	rrb(t_stacks *stacks)
{
	ft_printf("rrb\n");
	rrotate(stacks->b);
}

void	rrr(t_stacks *stacks)
{
	ft_printf("rrr\n");
	rrotate(stacks->a);
	rrotate(stacks->b);
}
