/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithms.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 17:25:15 by plepercq          #+#    #+#             */
/*   Updated: 2026/04/06 11:32:46 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_ALGORITHMS_H
# define SORT_ALGORITHMS_H

# include "libft.h"
# include "ps_utils.h"
# include "stack.h"
# include <limits.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

/*  TURK ALGORITHM  */
int		nrot(t_stack *node, int tail);
int		nrrot(t_stack *node, int tail);
void	sort_three_a(t_stacks *stacks);
t_stack	*get_closest_smaller(t_stack **stack, t_stack *node);
int		get_fewest_rotations(t_stack *node, t_stack *target, int *id);
void	rot_a_rrot_b(t_stacks *stacks, t_stack *cheapest);
void	rrot_a_rot_b(t_stacks *stacks, t_stack *cheapest);
void	rotate_both(t_stacks *stacks, t_stack *cheapest);
void	rrotate_both(t_stacks *stacks, t_stack *cheapest);
t_stack	*get_target(t_stack **stack, t_stack *node);
t_stack	*get_median(t_stack **stack);
t_stack	*evaluate_cost(t_stack **src, t_stack **dest);
void	move_cheapest_btoa(t_stacks *stacks);
void	turk_algorithm(t_stacks *stacks);

#endif