/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 13:59:32 by plepercq          #+#    #+#             */
/*   Updated: 2026/03/17 16:27:02 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	push(t_stack **src, t_stack **dst)
{
	t_stack	*node;

	if (*src == NULL)
		return ;
	node = *src;
	*src = node->next;
	node->next->prev = NULL;
	stack_index(*src);
	stack_add_front(dst, node);
}
