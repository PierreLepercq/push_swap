/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stacks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 15:37:46 by plepercq          #+#    #+#             */
/*   Updated: 2026/04/05 22:22:41 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_utils.h"

t_stacks	*stacks_new(void)
{
	t_stacks	*stacks;

	stacks = malloc(sizeof(t_stacks));
	if (!stacks)
		return (NULL);
    stacks->a = malloc(sizeof(t_stack *));
    stacks->b = malloc(sizeof(t_stack *));
    if (!stacks->a || !stacks->b)
    {
        free(stacks->a);
        free(stacks->b);
        free(stacks);
        return (NULL);
    }
	*stacks->a = NULL;
	*stacks->b = NULL;
	return (stacks);
}

void	stacks_free(t_stacks *stacks)
{
	stack_free(stacks->a);
	stack_free(stacks->b);
	free(stacks->a);
	free(stacks->b);
	free(stacks);
	stacks = NULL;
}

t_stacks	*init_stacks(int *values, int len)
{
	int			i;
	t_stack		*node;
	t_stacks	*stacks;

	stacks = stacks_new();
	if (!stacks)
		return (NULL);
	i = 0;
	while (i < len)
	{
		node = stack_new(values[i]);
		if (node == NULL)
			return (stacks_free(stacks), NULL);
		stack_add_back(stacks->a, node);
		i++;
	}
	return (stacks);
}
