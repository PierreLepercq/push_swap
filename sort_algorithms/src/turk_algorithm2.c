/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algorithm2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 15:35:16 by plepercq          #+#    #+#             */
/*   Updated: 2026/04/06 00:11:12 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_algorithms.h"

int	get_fewest_rotations(t_stack *node, t_stack *target, int *id)
{
	int	move_id;
	int	move1;
	int	move2;
	int	move3;
	int	move4;
	int	min_rots;

	move_id = 0;
	move1 = nrot(node) + nrrot(target);
	move2 = nrrot(node) + nrot(target);
	move3 = ft_max(nrot(node), nrot(target));
	move4 = ft_max(nrrot(node), nrrot(target));
	min_rots = ft_min(move1, move2);
	min_rots = ft_min(min_rots, move3);
	min_rots = ft_min(min_rots, move4);
	if (min_rots == move2)
		move_id = 1;
	if (min_rots == move3)
		move_id = 2;
	if (min_rots == move4)
		move_id = 3;
	if (id != NULL)
		*id = move_id;
	return (min_rots);
}

void	rot_a_rrot_b(t_stacks *stacks, t_stack *cheapest)
{
	moven(stacks, ra, nrot(cheapest));
	moven(stacks, rrb, nrrot(cheapest->target));
}

void	rrot_a_rot_b(t_stacks *stacks, t_stack *cheapest)
{
	moven(stacks, rra, nrrot(cheapest));
	moven(stacks, rb, nrot(cheapest->target));
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
	moven(stacks, rra, nrrot(cheapest));
	moven(stacks, rrb, nrrot(cheapest->target));
}
