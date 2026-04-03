/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rrotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 14:44:59 by plepercq          #+#    #+#             */
/*   Updated: 2026/04/02 21:12:26 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_utils.h"

int	rra(t_stacks *stacks)
{
	char	*str;
	t_list	*new;

	ft_printf("rra");
	rrotate(stacks->a);
}

int	rrb(t_stacks *stacks, t_list **instructions)
{
	ft_printf("rrb");
	rrotate(stacks->b);
}

int	rrr(t_stacks *stacks, t_list **instructions)
{
	ft_printf("rrr");
	rrotate(stacks->a);
	rrotate(stacks->b);
}