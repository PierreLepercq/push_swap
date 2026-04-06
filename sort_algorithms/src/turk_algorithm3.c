/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algorithm3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 15:35:19 by plepercq          #+#    #+#             */
/*   Updated: 2026/04/06 11:51:01 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_algorithms.h"

t_stack	*get_target(t_stack **stack, t_stack *node)
{
	if (stack_min(stack)->value > node->value)
		return (stack_max(stack));
	return (get_closest_smaller(stack, node));
}

t_stack	*get_median(t_stack **stack)
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
		if (!median)
			return (NULL);
		len++;
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
		node->cost = get_fewest_rotations(node, node->target, NULL);
		if (node->cost < cheapest->cost)
			cheapest = node;
		node = node->next;
		if (node == *src)
			break ;
	}
	return (cheapest);
}

void	move_cheapest_btoa(t_stacks *stacks)
{
	int		rot_id;
	t_stack	*cheapest;

	cheapest = evaluate_cost(stacks->b, stacks->a);
	get_fewest_rotations(cheapest, cheapest->target, &rot_id);
	ft_printf("\ncheapest = %i", cheapest->value);
	ft_printf("\ntarget = %i", cheapest->target->value);
	ft_printf("\nrot_id = %i\n\n", rot_id);
	if (rot_id == 0)
		rot_a_rrot_b(stacks, cheapest);
	if (rot_id == 1)
		rrot_a_rot_b(stacks, cheapest);
	if (rot_id == 2)
		rotate_both(stacks, cheapest);
	if (rot_id == 3)
		rrotate_both(stacks, cheapest);
	pa(stacks);
}

void	turk_algorithm(t_stacks *stacks)
{
	t_stack	*min;
	t_stack	*median;

	median = get_median(stacks->a);
	while (stack_len(stacks->a) > 3 && !stack_is_sorted(stacks->a))
	{
		pb(stacks);
		if ((*(stacks->b))->value > median->value)
			rb(stacks);
	}
	if (!stack_is_sorted(stacks->a))
		sort_three_a(stacks);
	while (stack_len(stacks->b) > 0)
	{
		stack_print(stacks->a, "A");
		stack_print(stacks->b, "B");
		move_cheapest_btoa(stacks);
	}
	stack_print(stacks->a, "A");
	stack_print(stacks->b, "B");
	ft_printf("\n> Move min to Head <\n");
	min = stack_min(stacks->a);
	if (stack_min(stacks->a)->id == 0)
		return ;
	if (nrot(min, 0) < nrrot(min, 0))
		moven(stacks, ra, nrot(min, 0));
	else
		moven(stacks, rra, nrrot(min, 0));
}
