/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 18:09:57 by plepercq          #+#    #+#             */
/*   Updated: 2026/03/25 18:53:47 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdlib.h>
# include <stddef.h>
# include "libft.h"

typedef struct s_stack
{
	int				id;
	int				value;
	int				cost;
	struct s_stack	*prev;
	struct s_stack	*next;
	struct s_stack	*target;
}	t_stack;

typedef struct s_stacks
{
	t_stack	**stack_a;
	t_stack	**stack_b;
}	t_stacks;

/*  UTILITIES   */
t_stack	*stack_new(int value);
void	stack_free(t_stack **stack);
int		stack_len(t_stack **stack);
void	stack_iter(t_stack **stack, void (*f)(void *));
void	stack_index(t_stack **stack);
void	stack_add_front(t_stack **stack, t_stack *new);
void	stack_add_back(t_stack **stack, t_stack *new);
t_stack	*stack_min(t_stack **stack);
t_stack	*stack_max(t_stack **stack);
void	stack_print(t_stack **stack, const char *label);
int		has_duplicates(t_stack **stack);

/*  OPERATORS   */
//	Push
void	push(t_stack **src, t_stack **dst);
void	pa(t_stacks *stacks);
void	pb(t_stacks *stacks);
// Rotate
void	rotate(t_stack **stack);
void	ra(t_stacks *stacks);
void	rb(t_stacks *stacks);
void	rr(t_stacks *stacks);
// Reverse rotate
void	rrotate(t_stack **stack);
void	rra(t_stacks *stacks);
void	rrb(t_stacks *stacks);
void	rrr(t_stacks *stacks);
// Swap
void	swap(t_stack **stack);
void	sa(t_stacks *stacks);
void	sb(t_stacks *stacks);
void	ss(t_stacks *stacks);

#endif