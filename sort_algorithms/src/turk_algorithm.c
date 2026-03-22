/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 17:19:07 by plepercq          #+#    #+#             */
/*   Updated: 2026/03/22 20:25:04 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_algorithms.h"

int	ascent_cost(t_stack	*node)
{
	int	cost;
	int	len;

	cost = 0;
	len = stack_len(&node);
	if (node->id * 2 < len)
		cost += node->id;
	else
		cost += len - node->id;
	return (cost);
}

void	evaluate_cost(t_stack **a_stack, t_stack **b_stack)
{
	int		len_a;
	int		len_b;
	t_stack	*node;
	t_stack	*target;

	if (*a_stack == NULL || *b_stack == NULL)
		return ;
	node = *a_stack;
	while (node != NULL)
	{
		node->cost = ascent_cost(node);
		target = stack_min(*b_stack);
		if (target->value > node->value)
			target = stack_max(*b_stack);
		else
		{
			while (target->next != NULL && target->next->value < node->value)
				target = target->next;
		}
		node->cost += ascent_cost(target);
	}
}

void	get_lowest_cost_node(t_stack **a_stack, t_stack **b_stack)
{
	int		cost;
	int		lowest;
	t_stack	*node;
	t_stack	*target;
	t_stack	*cheapest;

	if (*a_stack == NULL || *b_stack == NULL)
		return ;
	node = *a_stack;
	cost = 0;
	if (node->id * 2 < stack_len(a_stack))
		cost += node->id;
	else
		cost += stack_len(a_stack) - node->id;
	target = *b_stack;


}

void	turk_algorithm(t_stack **a_stack, t_stack **b_stack)
{
	while (stack_len(a_stack) > 3)
	{
		if (stack_len(b_stack) < 2)
		{
			push(a_stack, b_stack);
			continue ;
		}
		evaluate_cost(a_stack, b_stack);
	}
	evaluate_cost(a_stack, b_stack);
}
