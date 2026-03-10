/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 18:09:57 by plepercq          #+#    #+#             */
/*   Updated: 2026/03/10 19:21:39 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdlib.h>
# include <stddef.h>

typedef struct s_stack
{
	int				id;
	int				value;
	int				cost;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

/*  UTILITIES   */
t_stack	*stack_new(int value);
t_stack	*stack_first(t_stack *stack);
t_stack	*stack_last(t_stack *stack);
void	stack_iter(t_stack *stack, void (*f)(void *));
void	stack_index(t_stack *stack);
void	stack_add_front(t_stack **stack, t_stack *new);
void	stack_add_back(t_stack **stack, t_stack *new);

/*  OPERATORS   */
void	swap(t_stack **stack);
void	push(t_stack **src, t_stack **dst);
void	rotate(t_stack **stack);
void	rrotate(t_stack **stack);

#endif