/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algorithm3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 15:14:20 by plepercq          #+#    #+#             */
/*   Updated: 2026/04/04 10:53:04 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_algorithms.h"

/*	ROTATIONS COUNT	*/
int	nrot(t_stack *n)
{
	return (n->id);
}

int	nrrot(t_stack *n)
{
	return (stack_len(n) - n->id);
}

/*	*/
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

t_stack	*get_closest_smaller(t_stack *stack, t_stack *node)
{
	t_stack	*cursor;
	t_stack	*closest;

	closest = stack_min(stack);
	cursor = stack;
	while (cursor->next != stack)
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

t_stack	*get_target(t_stack *stack, t_stack *node)
{
	t_stack	*cursor;
	t_stack	*target;

	if (stack_min(stack)->value > node->value)
		return (stack_max(stack));
	return (get_closest_smaller(stack, node));
}

t_stack	*get_median(t_stack *stack)
{
	int		id;
	int		len;
	t_stack	*median;

	len = stack_len(stack);
	id = len / 2;
	if (len % 2 == 1)
		id++;
	len = 0;
	median = stack_max(stack);
	while (len < id)
	{
		median = get_closest_smaller(stack, median);
	}
	return (median);
}

t_stack	*evaluate_cost(t_stack **src, t_stack **dest)
{
	t_stack	*node;
	t_stack	*cheapest;

	if (*src == NULL || *dest == NULL)
		return (NULL);
	node = *src;
	cheapest = node;
	while (node)
	{
		node->target = get_target(dest, node);
		node->cost = get_fewest_rots_to_head(node, node->target);
		if (node->cost < cheapest->cost)
			cheapest = node;
		node = node->next;
		if (node == src)
			break ;
	}
	return (cheapest);
}

void	turk_algorithm(t_stacks *stacks)
{
	t_stack	*median;

	median = get_median(stacks->a);
	while (stack_len(stacks->a) > 3 && !stack_is_sorted(stacks->a))
	{
		pb(stacks);
		if ((*(stacks->b))->value > median->value)
			rb(stacks);
	}
	if (!stack_is_sorted(stacks->a))
		sort_three(stacks->a);
	while (stack_len(stacks->b) > 0)
	{
		evaluate_cost(stacks->b, stacks->a);
		move_cheapest(stacks->b, stacks->a, 1);
	}
	rotate_to_head(stack_min(stacks->a), stacks->a);
}
