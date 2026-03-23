/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 14:32:30 by plepercq          #+#    #+#             */
/*   Updated: 2026/03/23 15:51:01 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//TODO : remove libft

#include "libft.h"
#include "stack.h"
#include <stdio.h>

void	rotate(t_stack **stack)
{
	ft_printf("\n#####################");
	ft_printf("\n#      ROTATE       #");
	ft_printf("\n#####################\n");
	*stack = (*stack)->next;
	stack_index(stack);
}

void	rrotate(t_stack **stack)
{
	ft_printf("\n#####################");
	ft_printf("\n#      RROTATE      #");
	ft_printf("\n#####################\n");
	*stack = (*stack)->prev;
	stack_index(stack);
}
