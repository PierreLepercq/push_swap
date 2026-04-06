/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algorithm2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 15:35:16 by plepercq          #+#    #+#             */
/*   Updated: 2026/04/06 11:37:36 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_algorithms.h"

int	get_fewest_rotations(t_stack *node, t_stack *target, int *id)
{
	int	rot_id;
	int	min_rots;

	rot_id = 0;
	min_rots = nrot(node, 0) + nrrot(target, 1);
	if (min_rots > nrrot(node, 0) + nrot(target, 1))
	{
		min_rots = nrrot(node, 0) + nrot(target, 1);
		rot_id = 1;
	}
	if (min_rots > ft_max(nrot(node, 0), nrot(target, 1)))
	{
		min_rots = ft_max(nrot(node, 0), nrot(target, 1));
		rot_id = 2;
	}
	if (min_rots > ft_max(nrrot(node, 0), nrrot(target, 1)))
	{
		min_rots = ft_max(nrrot(node, 0), nrrot(target, 1));
		rot_id = 3;
	}
	if (id != NULL)
		*id = rot_id;
	return (min_rots);
}

void	rot_a_rrot_b(t_stacks *stacks, t_stack *cheapest)
{
	moven(stacks, ra, nrrot(cheapest->target, 1));
	moven(stacks, rrb, nrot(cheapest, 0));
}

void	rrot_a_rot_b(t_stacks *stacks, t_stack *cheapest)
{
	moven(stacks, rb, nrrot(cheapest, 0));
	moven(stacks, rra, nrot(cheapest->target, 1));
}

void	rotate_both(t_stacks *stacks, t_stack *cheapest)
{
	moven(stacks, rr, ft_min(nrot(cheapest, 0), nrot(cheapest->target, 1)));
	moven(stacks, ra, nrot(cheapest->target, 1));
	moven(stacks, rb, nrot(cheapest, 0));
}

void	rrotate_both(t_stacks *stacks, t_stack *cheapest)
{
	moven(stacks, rrr, ft_min(nrrot(cheapest, 0), nrrot(cheapest->target, 1)));
	moven(stacks, rra, nrrot(cheapest->target, 1));
	moven(stacks, rrb, nrrot(cheapest, 0));
}
