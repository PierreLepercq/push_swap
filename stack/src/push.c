/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 13:59:32 by plepercq          #+#    #+#             */
/*   Updated: 2026/03/23 16:21:21 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//TODO : remove libft

#include "libft.h"
#include "stack.h"

void	push(t_stack **src, t_stack **dst)
{
	t_stack	*node;

	ft_printf("\n#####################");
	ft_printf("\n#       PUSH        #");
	ft_printf("\n#####################\n");
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
}
