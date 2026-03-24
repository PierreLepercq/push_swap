/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 17:19:07 by plepercq          #+#    #+#             */
/*   Updated: 2026/03/24 18:26:09 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_algorithms.h"

int	abs(int value)
{
	if (value < 0)
		return (-value);
	return (value);
}

int	get_rotations_count(t_stack **stack, t_stack *node)
{
	int	len;
	int	count;

	len = stack_len(stack);
	if (node->id * 2 < len)
		count = -1 * node->id;
	else
		count = len - node->id;
	return (count);
}

t_stack	*get_closest_smaller_target(t_stack *node, t_stack **stack)
{
	t_stack	*min;
	t_stack	*target;

	min = stack_min(stack);
	if (min->value > node->value)
		return (stack_max(stack));
	target = min;
	while (target->prev != min)
	{
		if (target->prev->value > node->value)
			break ;
		target = target->prev;
	}
	return (target);
}

t_stack	*evaluate_cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*node;
	t_stack	*target;
	t_stack	*cheapest;

	(void)node;
	(void)target;

	if (*stack_a == NULL || *stack_b == NULL)
		return (NULL);
	node = *stack_a;
	cheapest = node;
	while (node)
	{
		node->target = get_closest_smaller_target(node, stack_b);
		node->cost = abs(get_rotations_count(stack_a, node));
		node->cost += abs(get_rotations_count(stack_a, node->target));
		if (node->cost < cheapest->cost)
			cheapest = node;
		node = node->next;
		if (node == *stack_a)
			break ;
	}
	return (cheapest);
}

//void	move_to_head(t_stack *node)
//{
//	int	cost;
//	int	len;
//
//	cost = 0;
//	len = stack_len(&node);
//	if (node->id * 2 < len)
//		cost += node->id;
//	else
//		cost += len - node->id;
//	return (cost);
//}

void	mode_node_to_stack_head(t_stack *node, t_stack **stack)
{
	int	i;
	int	step;
	int	rot_count;

	rot_count = get_rotations_count(stack, node);
	if (rot_count == 0)
		return ;
	i = 0;
	step = 1;
	if (rot_count < 0)
		step = -1;
	while (i != rot_count)
	{
		if (step == 1)
			rrotate(stack);
		else
			rotate(stack);
		i += step;
	}
}

void	move_cheapest(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheapest;

	if (*stack_a == NULL || *stack_b == NULL)
		return ;
	cheapest = evaluate_cost(stack_a, stack_b);
	mode_node_to_stack_head(cheapest, stack_a);
	mode_node_to_stack_head(cheapest->target, stack_b);
	push(stack_a, stack_b);
}

void	turk_algorithm(t_stack **stack_a, t_stack **stack_b)
{
	while (stack_len(stack_a) > 3)
	{
		stack_print(stack_a, "stack A");
		stack_print(stack_b, "stack B");
		if (stack_len(stack_b) < 2)
		{
			push(stack_a, stack_b);
			continue ;
		}
		move_cheapest(stack_a, stack_b);
	}
	stack_print(stack_a, "stack A");
	stack_print(stack_b, "stack B");

	if ((*stack_a)->value < (*stack_a)->next->value)

	// while in b stack, get lowest, move and reevaluate
	//while (stack_len(stack_b) > 0)
	//{
	//
	//}
}
