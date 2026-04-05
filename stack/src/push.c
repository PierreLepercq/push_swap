/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 13:59:32 by plepercq          #+#    #+#             */
/*   Updated: 2026/04/05 19:07:17 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	push(t_stack **src, t_stack **dst)
{
	t_stack	*node;

	if (*src == NULL)
		return ;
	node = *src;
	if (stack_len(src) == 1)
		*src = NULL;
	else
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
		*src = node->next;
	}
	stack_index(src);
	stack_add_front(dst, node);
	*dst = node;
}
