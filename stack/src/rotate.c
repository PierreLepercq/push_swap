/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 14:32:30 by plepercq          #+#    #+#             */
/*   Updated: 2026/03/22 16:26:00 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//TODO : remove libft

#include "libft.h"
#include "stack.h"
#include <stdio.h>

void	rotate(t_stack **stack)
{
	t_stack	*first;

	ft_printf("\n#####################");
	ft_printf("\n#      ROTATE       #");
	ft_printf("\n#####################\n");
	first = stack_first(*stack);
	if (first->next == NULL)
		return ;
	*stack = first->next;
	first->next->prev = NULL;
	first->next = NULL;
	stack_index(stack);
	stack_add_back(stack, first);
}

void	rrotate(t_stack **stack)
{
	t_stack	*last;

	ft_printf("\n#####################");
	ft_printf("\n#      RROTATE      #");
	ft_printf("\n#####################\n");
	last = stack_last(*stack);
	if (last->prev == NULL)
		return ;
	last->prev->next = NULL;
	last->prev = NULL;
	stack_add_front(stack, last);
	stack_index(stack);
	*stack = last;
}
