/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 13:59:32 by plepercq          #+#    #+#             */
/*   Updated: 2026/03/22 16:35:22 by plepercq         ###   ########.fr       */
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
	node = stack_first(*src);
	if (node->next != NULL)
	{
		*src = node->next;
		node->next->prev = NULL;
	}
	else
		*src = NULL;
	node->next = NULL;
	node->id = 0;
	stack_index(src);
	stack_add_front(dst, node);
}
