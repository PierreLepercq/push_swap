/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algorithm3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 15:14:20 by plepercq          #+#    #+#             */
/*   Updated: 2026/04/04 15:10:55 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_algorithms.h"
#include <stdbool.h>

/*	ROTATIONS COUNT	*/
int	nrot(t_stack *node)
{
	return (node->id);
}

int	nrrot(t_stack *node)
{
	return (stack_len(node) - node->id);
}

void	moven(t_stacks *stacks, void (*move_func)(void *), int n)
{
	int	i;

	i = 0;
	while (i++ < n)
	{
		move_func(stacks);
	}
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

int	*get_fewest_rotations_id(t_stack *node, t_stack *target)
{
	int	id;
	int	rots;
	int	comp;

	id = 0;
	rots = nrot(node) + nrrot(target);
	comp = nrrot(node) + nrot(target);
	if (comp < rots)
	{
		id = 1;
		rots = comp;
	}
	comp = ft_max(nrot(node), nrot(target));
	if (comp < rots)
	{
		id = 2;
		rots = comp;
	}
	comp = ft_max(nrrot(node), nrrot(target));
	if (comp < rots)
	{
		id = 3;
		rots = comp;
	}
	return (id);
}

void	rot_a_rrot_b(t_stacks *stacks, t_stack *cheapest)
{
	moven(stacks->a, ra, nrot(cheapest));
	moven(stacks->b, rrb, nrot(cheapest->target));
}

void	rrot_a_rot_b(t_stacks *stacks, t_stack *cheapest)
{
	moven(stacks->a, rra, nrot(cheapest));
	moven(stacks->b, rb, nrot(cheapest->target));
}

void	rotate_both(t_stacks *stacks, t_stack *cheapest)
{
	moven(stacks, rr, ft_min(nrot(cheapest), nrot(cheapest->target)));
	moven(stacks, ra, nrot(cheapest));
	moven(stacks, rb, nrot(cheapest->target));
}

void	rrotate_both(t_stacks *stacks, t_stack *cheapest)
{
	moven(stacks, rrr, ft_min(nrrot(cheapest), nrrot(cheapest->target)));
	moven(stacks, rra, nrot(cheapest));
	moven(stacks, rrb, nrot(cheapest->target));
}

void	move_cheapest_btoa(t_stacks *stacks)
{
	int		rot_id;
	t_stack	*cheapest;

	cheapest = evaluate_cost(stacks->b, stacks->a);
	rot_id = get_fewest_rotations_id(cheapest, cheapest->target);
	if (rot_id == 0)
		rot_a_rrot_b(stacks, cheapest);
	if (rot_id == 1)
		rrot_a_rot_b(stacks, cheapest);
	if (rot_id == 2)
		rotate_both(stacks, cheapest);
	if (rot_id == 3)
		rrotate_both(stacks, cheapest);
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
		sort_three(stacks->a);
	while (stack_len(stacks->b) > 0)
	{
		move_cheapest_btoa(stacks);
	}
	min = stack_min(stacks->a);
	if (stack_min(stacks->a->id == 0))
		return ;
	if (nrot(min) < nrrot(min))
		moven(stacks, ra, nrot(min));
	else
		moven(stacks, rra, nrrot(min));
}
