/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algorithm2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 15:14:20 by plepercq          #+#    #+#             */
/*   Updated: 2026/04/02 17:06:29 by plepercq         ###   ########.fr       */
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

void	rotate_to_head(t_stack *node, t_stack **stack)
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

t_moveset	*init_moveset(
	void (*func_push)(void *),
	void (*func_rotate)(void *),
	void (*func_rrotate)(void *),
	void (*func_swap)(void *))
{
	t_moveset	*ms;

	ms = malloc(sizeof(t_moveset));
	if (!ms)
		return (NULL);
	ms->p = func_push;
	ms->r = func_rotate;
	ms->rr = func_rrotate;
	ms->s = func_swap;
}

t_movesets	*get_movesets(void)
{
	t_movesets	*ms;
	t_moveset	*ms_a;
	t_moveset	*ms_b;

	ms = malloc(sizeof(t_movesets));
	if (!ms)
		return (NULL);
	ms_a = malloc(sizeof(t_moveset));
	if (!ms_a)
		return (free(ms), NULL);
	ms_b = malloc(sizeof(t_moveset));
	if (!ms_b)
		return (free(ms), free(ms_a), NULL);
	ms->ms_a = ms_a;
	ms->ms_b = ms_b;
	return (ms);
}

void	turk_algorithm(t_stacks *stacks)
{
	t_stack	*median;

	median = get_median(stacks->stack_a);
	while (stack_len(stacks->stack_a) > 3 && !stack_is_sorted(stacks->stack_a))
	{
		pb(stacks);
		if ((*(stacks->stack_b))->value > median->value)
			rb(stacks);
	}
	if (!stack_is_sorted(stacks->stack_a))
		sort_three(stacks->stack_a);
	while (stack_len(stacks->stack_b) > 0)
	{
		evaluate_cost(stacks->stack_b, stacks->stack_a);
		move_cheapest(stacks->stack_b, stacks->stack_a, 1);
	}
	mode_to_head(stack_min(stacks->stack_a), stacks->stack_a);
	while (stack_len(stacks->stack_b) > 0)
	{
		evaluate_cost(stacks->stack_b, stacks->stack_a);
		move_cheapest(stacks->stack_b, stacks->stack_a, 1);
	}
	mode_node_to_stack_head(stack_min(stacks->stack_a), stacks->stack_a);
	stack_print(stacks->stack_a, "stack A");
	stack_print(stacks->stack_b, "stack B");
}
