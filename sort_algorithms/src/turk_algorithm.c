/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 17:19:07 by plepercq          #+#    #+#             */
/*   Updated: 2026/03/23 18:26:38 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_algorithms.h"

int	get_ascent_cost(t_stack	*node)
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

t_stack	*get_closest_smaller_target(t_stack *node, t_stack **stack)
{
	t_stack	*min;
	t_stack	*target;

	min = stack_min(stack);
	if (min->value > node->value)
		return (stack_max(stack));
	target = min;
	while (target->next != min)
	{
		if (target->next->value > node->value)
			break ;
		target = target->next;
	}
	return (target);
}

t_stack	*evaluate_cost(t_stack **a_stack, t_stack **b_stack)
{
	t_stack	*node;
	t_stack	*target;
	t_stack	*cheapest;

	if (*a_stack == NULL || *b_stack == NULL)
		return ;
	node = *a_stack;
	cheapest = node;
	while (node)
	{
		node->target = get_closest_smaller_target(node, b_stack);
		node->cost = get_ascent_cost(node);
		node->cost += get_ascent_cost(node->target);
		if (node->cost < cheapest->cost)
			cheapest = node;
		node = node->next;
		if (node == a_stack)
			break ;
	}
	return (cheapest);
}

void	move_to_head()

void	move_cheapest(t_stack **a_stack, t_stack **b_stack)
{
	t_stack	*node;
	t_stack	*cheapest;

	if (*a_stack == NULL || *b_stack == NULL)
		return ;
	cheapest = evaluate_cost(a_stack, b_stack);
	
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
		move_cheapest(a_stack, b_stack);
	}
	// while in b stack, get lowest, move and reevaluate
	while (stack_len(b_stack) > 0)
	{

	}
}
