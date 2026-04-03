/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 14:27:58 by plepercq          #+#    #+#             */
/*   Updated: 2026/04/03 20:10:26 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_UTILS_H
# define PS_UTILS_H

# include "libft.h"
# include "stack.h"

typedef struct s_moveset
{
	void		(*p)(void *);
	void		(*r)(void *);
	void		(*rr)(void *);
	void		(*s)(void *);
}				t_moveset;

typedef	struct s_stack_ms
{
	t_stack		**st;
	t_moveset	*ms;
}				t_stack_ms;

typedef struct s_stacks
{
	t_stack_ms		*a;
	t_stack_ms		*b;
}				t_stacks;

/*	STACKS		*/
t_stacks		*stacks_new(void);
void			stacks_free(t_stacks **stacks);

/*	ACTIONS		*/
//	Utilities
t_list			*action_new(const char *str);
void			action_add_back(t_list **lst, t_list *node);
void			action_insert(t_list *lst, t_list *node);
void			action_del(t_list **lst, t_list *node);
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