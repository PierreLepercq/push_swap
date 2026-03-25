/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 17:19:07 by plepercq          #+#    #+#             */
/*   Updated: 2026/03/25 16:01:15 by plepercq         ###   ########.fr       */
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
	t_stack	*cursor;
	t_stack	*target;

	if (stack_min(stack)->value > node->value)
		return (stack_max(stack));
	target = stack_min(stack);
	cursor = *stack;
	while (cursor->next != *stack)
	{
		if (cursor->value > target->value && cursor->value < node->value)
			target = cursor;
		cursor = cursor->next;
	}
	if (cursor->value > target->value && cursor->value < node->value)
		target = cursor;
	return (target);
}

t_stack	*evaluate_cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*node;
	t_stack	*cheapest;

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
	ft_printf("\n----------------------------");
	ft_printf("\ncheapest : %i\n", cheapest->value);
	ft_printf("target : %i\n", cheapest->target->value);
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

void	move_cheapest(t_stack **src, t_stack **dst, int descend)
{
	t_stack	*cheapest;

	(void)descend;

	if (*src == NULL || *src == NULL)
		return ;
	cheapest = evaluate_cost(src, dst);
	mode_node_to_stack_head(cheapest, src);
	mode_node_to_stack_head(cheapest->target, dst);
	if (descend == 1)
		rotate(dst);
	push(src, dst);
}

void	sort_three(t_stack **stack)
{
	t_stack	*max;

	max = stack_max(stack);
	if (max->id == 0)
		rotate(stack);
	if (max->id == 1)
		rrotate(stack);
	if ((*stack)->value > (*stack)->next->value)
		swap(stack);
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
		move_cheapest(stack_a, stack_b, 0);
	}
	stack_print(stack_a, "stack A");
	stack_print(stack_b, "stack B");

	sort_three(stack_a);

	stack_print(stack_a, "stack A");
	stack_print(stack_b, "stack B");

	while (stack_len(stack_b) > 0)
	{
		evaluate_cost(stack_b, stack_a);
		move_cheapest(stack_b, stack_a, 1);
		stack_print(stack_a, "stack A");
		stack_print(stack_b, "stack B");
	}

	mode_node_to_stack_head(stack_min(stack_a), stack_a);

	stack_print(stack_a, "stack A");
	stack_print(stack_b, "stack B");
}
