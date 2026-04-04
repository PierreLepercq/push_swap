/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algorithm2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 15:14:20 by plepercq          #+#    #+#             */
/*   Updated: 2026/04/03 17:29:41 by plepercq         ###   ########.fr       */
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

void	rotate_one(t_stack *node, t_moveset *ms)
{
	int	i;
	int	rot;
	int	rrot;

	rot = nrot(node);
	rrot = nrrot(node);
	if (rot < rrot)
	{
		i = rot;
		while (i-- > 0)
			ms->r(node);
	}
	else
	{
		i = rrot;
		while (i-- > 0)
			ms->rr(node);
	}
}

void	rotate_both()

void	rotate_to_head(t_stack *node, t_moveset ms)
{
	int	i;
	int	rot;
	int	rrot;

	rot = nrot(node);
	rrot = nrrot(node);
	i = ft_min(rot, rrot);
	while (i > 0)
	{
		
	}
	if (nrot(node) < nrrot(node))
		rotdir = 1;

}

t_moveset	*create_moveset(
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
	ms_a = create_moveset(pa, ra, rra, sa);
	if (!ms_a)
		return (free(ms), NULL);
	ms_b = create_moveset(pb, rb, rrb, sb);;
	if (!ms_b)
		return (free(ms), free(ms_a), NULL);
	ms->a = ms_a;
	ms->b = ms_b;
	return (ms);
}

void	free_movesets(t_movesets *ms)
{
	free(ms->a);
	free(ms->b);
	free(ms);
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


	
	while (stack_len(stacks->b) > 0)
	{
		evaluate_cost(stacks->b, stacks->a);
		move_cheapest(stacks->b, stacks->a, 1);
	}
	mode_node_to_stack_head(stack_min(stacks->a), stacks->a);
	stack_print(stacks->a, "stack A");
	stack_print(stacks->b, "stack B");
}
