/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 14:27:58 by plepercq          #+#    #+#             */
/*   Updated: 2026/04/04 15:26:46 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_UTILS_H
# define PS_UTILS_H

# include "libft.h"
# include "stack.h"

typedef struct s_stacks
{
	t_stack		**a;
	t_stack		**b;
}				t_stacks;

/*	STACKS		*/
t_stacks		*stacks_new(void);
void			stacks_free(t_stacks **stacks);

/*	ACTIONS		*/
void			moven(t_stacks *stacks, void (*move_func)(void *), int n);
//	Push
void			pa(t_stacks *stacks);
void			pb(t_stacks *stacks);
// Rotate
void			ra(t_stacks *stacks);
void			rb(t_stacks *stacks);
void			rr(t_stacks *stacks);
// Reverse rotate
void			rra(t_stacks *stacks);
void			rrb(t_stacks *stacks);
void			rrr(t_stacks *stacks);
// Swap
void			sa(t_stacks *stacks);
void			sb(t_stacks *stacks);
void			ss(t_stacks *stacks);

#endif