/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 14:32:33 by plepercq          #+#    #+#             */
/*   Updated: 2026/03/23 15:48:35 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//TODO : remove libft

#include "libft.h"
#include "stack.h"

void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	ft_printf("\n#####################");
	ft_printf("\n#       SWAP        #");
	ft_printf("\n#####################\n");
	if (*stack == NULL)
		return ;
	first = *stack;
	second = first->next;
	if (second == first)
		return ;
	first->prev->next = second;
	second->prev = first->prev;
	first->next = second->next;
	second->next->prev = first;
	second->next = first;
	first->prev = second;
	second->id = 0;
	first->id = 1;
	*stack = second;
}
