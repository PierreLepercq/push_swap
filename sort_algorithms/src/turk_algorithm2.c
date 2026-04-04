/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algorithm2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 15:35:16 by plepercq          #+#    #+#             */
/*   Updated: 2026/04/04 15:43:39 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_algorithms.h"

int	*get_fewest_rotations(t_stack *node, t_stack *target, int *id)
{
	int	rots;
	int	comp;

	*id = 0;
	rots = nrot(node) + nrrot(target);
	comp = nrrot(node) + nrot(target);
	if (comp < rots)
	{
		*id = 1;
		rots = comp;
	}
	comp = ft_max(nrot(node), nrot(target));
	if (comp < rots)
	{
		*id = 2;
		rots = comp;
	}
	comp = ft_max(nrrot(node), nrrot(target));
	if (comp < rots)
	{
		*id = 3;
		rots = comp;
	}
	return (rots);
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
