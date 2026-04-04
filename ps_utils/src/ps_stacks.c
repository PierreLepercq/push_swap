/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stacks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 15:37:46 by plepercq          #+#    #+#             */
/*   Updated: 2026/04/04 10:53:08 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_utils.h"

t_stacks	*stacks_new(void)
{
	t_stack		**a;
	t_stack		**b;
	t_moveset	*ms_a;
	t_moveset	*ms_b;
	t_stacks	*stacks;

	stacks = malloc(sizeof(t_stacks *));
	if (!stacks)
		return (NULL);
	a = malloc(sizeof(t_stack **));
	b = malloc(sizeof(t_stack **));
	ms_a = init;
	if (!a || !b)
	{
		stack_free(a);
		stack_free(b);
		free(stacks);
		return (NULL);
	}
	stacks->a = a;
	stacks->b = b;
	return (stacks);
}

void	stacks_free(t_stacks **stacks)
{
	stack_free((*stacks)->a);
	stack_free((*stacks)->b);
	ft_lstclear((*stacks)->actions, free);
	stacks = NULL;
	free(stacks);
}
