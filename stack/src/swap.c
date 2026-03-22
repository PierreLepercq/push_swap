/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 14:32:33 by plepercq          #+#    #+#             */
/*   Updated: 2026/03/22 16:27:09 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//TODO : remove libft

#include "libft.h"
#include "stack.h"

void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	ft_printf("\n#####################");
	ft_printf("\n#       SWAP        #");
	ft_printf("\n#####################\n");
	if (*stack == NULL)
		return ;
	first = stack_first(*stack);
	second = first->next;
	if (second == NULL)
		return ;
	third = second->next;
	first->id = 1;
	first->next = third;
	first->prev = second;
	second->id = 0;
	second->next = first;
	second->prev = NULL;
	*stack = second;
}
