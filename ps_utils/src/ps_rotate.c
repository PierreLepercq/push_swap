/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 14:45:02 by plepercq          #+#    #+#             */
/*   Updated: 2026/04/05 23:20:21 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_utils.h"

void	ra(t_stacks *stacks)
{
	ft_printf("ra\n");
	rotate(stacks->a);
}

void	rb(t_stacks *stacks)
{
	ft_printf("rb\n");
	rotate(stacks->b);
}

void	rr(t_stacks *stacks)
{
	ft_printf("rr\n");
	rotate(stacks->a);
	rotate(stacks->b);
}
