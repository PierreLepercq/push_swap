/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algorithm2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 15:35:16 by plepercq          #+#    #+#             */
/*   Updated: 2026/04/06 17:21:36 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_algorithms.h"

int	get_fewest_rotations(t_stack *node, t_stack *target, int *id)
{
	int	rot_id;
	int	min_rots;

	rot_id = 0;
	min_rots = nrot(node) + nrrot(target);
	if (min_rots > nrrot(node) + nrot(target))
	{
		min_rots = nrrot(node) + nrot(target);
		rot_id = 1;
	}
	if (min_rots > ft_max(nrot(node), nrot(target)))
	{
		min_rots = ft_max(nrot(node), nrot(target));
		rot_id = 2;
	}
	if (min_rots > ft_max(nrrot(node), nrrot(target)))
	{
		min_rots = ft_max(nrrot(node), nrrot(target));
		rot_id = 3;
	}
	if (id != NULL)
		*id = rot_id;
	return (min_rots);
}

void	rrot_a_rot_b(t_stacks *stacks, t_stack *cheapest)
{
	moven(stacks, rra, nrrot(cheapest->target));
	moven(stacks, rb, nrot(cheapest));
}

void	rot_a_rrot_b(t_stacks *stacks, t_stack *cheapest)
{
	moven(stacks, ra, nrot(cheapest->target));
	moven(stacks, rrb, nrrot(cheapest));
}

void	rotate_both(t_stacks *stacks, t_stack *cheapest)
{
	moven(stacks, rr, ft_min(nrot(cheapest), nrot(cheapest->target)));
	moven(stacks, ra, nrot(cheapest->target));
	moven(stacks, rb, nrot(cheapest));
}

void	rrotate_both(t_stacks *stacks, t_stack *cheapest)
{
	moven(stacks, rrr, ft_min(nrrot(cheapest), nrrot(cheapest->target)));
	moven(stacks, rra, nrrot(cheapest->target));
	moven(stacks, rrb, nrrot(cheapest));
}
