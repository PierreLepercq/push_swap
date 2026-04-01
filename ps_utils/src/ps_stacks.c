/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stacks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 15:37:46 by plepercq          #+#    #+#             */
/*   Updated: 2026/04/01 15:46:57 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_utils.h"

t_stacks	*stacks_new(void)
{
	t_stack		**stack_a;
	t_stack		**stack_b;
	t_list		**actions;
	t_stacks	*stacks;

	stacks = malloc(sizeof(t_stacks *));
	if (!stacks)
		return (NULL);
	stack_a = malloc(sizeof(t_stack **));
	stack_b = malloc(sizeof(t_stack **));
	actions = malloc(sizeof(t_list **));
	if (!stack_a || !stack_b || !actions)
	{
		stack_free(stack_a);
		stack_free(stack_b);
		ft_lstclear(actions, free);
		free(stacks);
		return (NULL);
	}
	stacks->stack_a = stack_a;
	stacks->stack_b = stack_b;
	stacks->actions = actions;
	return (stacks);
}

void	stacks_free(t_stacks **stacks)
{
	stack_free((*stacks)->stack_a);
	stack_free((*stacks)->stack_b);
	ft_lstclear((*stacks)->actions, free);
	stacks = NULL;
	free(stacks);
}
