/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algorithm1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 17:19:07 by plepercq          #+#    #+#             */
/*   Updated: 2026/04/02 16:41:13 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_algorithms.h"

int	nrot(t_stack *n)
{
	return (n->id);
}

int	nrrot(t_stack *n)
{
	return (stack_len(n) - n->id);
}

int	*get_fewest_rots_to_head(t_stack *n1, t_stack *n2)
{
	int	rots;
	int	comp;
	int	common;

	common = 0;
	rots = nrot(n1) + nrrot(n2);
	comp = nrrot(n1) + nrot(n2);
	if (comp < rots)
		rots = comp;
	comp = ft_max(nrot(n1), nrot(n2));
//	if (comp < rots)
//	{
//		rots = comp;
//		common = ft_min()
//	}
//	comp = ft_max(nrrot(n1), nrrot(n2));
//	if (comp < rots)
//	{
//		rots = comp;
//	}
//
//
//
//	comp = nrot(n1) + nrrot(n2);
//	if (comp < rots)
//		rots = comp;
//	comp = nrrot(n1) + nrot(n2);
//	if (comp < rots)
//		rots = comp;
//	return (rots);
}

t_list	*rotate_to_head1()

int	*rotate_to_head(t_stacks stacks, t_stack *node)
{
	int	rots;
	int	min;

	min = get_fewest_rots_to_head(node, node->target);
	if (min == ft_max(nrot(node), nrot(node->target)))
		return (rotate_to_head1());
	if (min == ft_max(nrrot(node), nrrot(node->target)))
		return (0);
	if (min == nrot(node) + nrrot(node->target))
		return (0);
	if (min == nrrot(node) + nrot(node->target))
		return (0);
	return (rots);
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

t_stack	*get_closest_smaller(t_stack *node)
{
	t_stack	*cursor;
	t_stack	*closest;

	closest = stack_min(node);
	cursor = node;
	while (cursor->next != node)
	{
		if (cursor->value > closest->value && cursor->value < node->value)
			closest = cursor;
		cursor = cursor->next;
	}
	if (cursor->value > node->value && cursor->value < node->value)
		closest = cursor;
	if (closest == node)
		closest = NULL;
	return (closest);
}

t_stack	*evaluate_cost(t_stack **s1, t_stack **s2)
{
	t_stack	*node;
	t_stack	*cheapest;

	if (*s1 == NULL || *s2 == NULL)
		return (NULL);
	node = *s1;
	cheapest = node;
	while (node)
	{
		node->target = get_closest_smaller_target(node, s2);
		node->cost = get_fewest_rots_to_head(node, node->target);
		if (node->cost < cheapest->cost)
			cheapest = node;
		node = node->next;
		if (node == s1)
			break ;
	}
	return (cheapest);
}

//ft_printf("\n----------------------------");
//ft_printf("\ncheapest : %i\n", cheapest->value);
//ft_printf("target : %i\n", cheapest->target->value);

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

t_stack	*get_median(t_stack	*stack)
{
	int	id;
	int	len;
	t_stack	*median;

	len = stack_len(stack);
	id = len / 2;
	if (len % 2 == 1)
		id++;
	len = 0;
	median = stack_max(stack);
	while (len < id)
	{
		median = get_closest_smaller(median);
	}
	return (median);
}

void	turk_algorithm(t_stacks *stacks)
{
	t_stack	*median;

	median = get_median(stacks->stack_a);
	while (stack_len(stacks->stack_a) > 3)
	{
		if (stack_len(stacks->stack_b) < 2)
		{
			pa(stacks);
			continue ;
		}
		move_cheapest(stacks->stack_a, stacks->stack_b, 0);
	}
	sort_three(stacks->stack_a);
	while (stack_len(stacks->stack_b) > 0)
	{
		evaluate_cost(stacks->stack_b, stacks->stack_a);
		move_cheapest(stacks->stack_b, stacks->stack_a, 1);
	}
	mode_node_to_stack_head(stack_min(stacks->stack_a), stacks->stack_a);
	stack_print(stacks->stack_a, "stack A");
	stack_print(stacks->stack_b, "stack B");
}
