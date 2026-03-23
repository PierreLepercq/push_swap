/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 18:09:57 by plepercq          #+#    #+#             */
/*   Updated: 2026/03/23 16:34:49 by plepercq         ###   ########.fr       */
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

/*  UTILITIES   */
t_stack	*stack_new(int value);
int		stack_len(t_stack **stack);
void	stack_iter(t_stack **stack, void (*f)(void *));
void	stack_index(t_stack **stack);
void	stack_add_front(t_stack **stack, t_stack *new);
void	stack_add_back(t_stack **stack, t_stack *new);
void	stack_free(t_stack **stack);
int		has_duplicates(t_stack **stack);
t_stack	*stack_min(t_stack **stack);
t_stack	*stack_max(t_stack **stack);
void	stack_print(t_stack **stack, const char *label);

/*  OPERATORS   */
void	swap(t_stack **stack);
void	push(t_stack **src, t_stack **dst);
void	rotate(t_stack **stack);
void	rrotate(t_stack **stack);

#endif