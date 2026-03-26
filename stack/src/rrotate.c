/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 18:31:01 by plepercq          #+#    #+#             */
/*   Updated: 2026/03/26 11:19:51 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	rrotate(t_stack **stack)
{
	*stack = (*stack)->prev;
	stack_index(stack);
}

int	rra(t_stacks *stacks, t_list **instructions)
{
	char	*str;
	t_list	*new;

	ft_printf("> R Rotate A");
	str = malloc(sizeof(char) * 4);
	if (str == NULL)
		return (0);
	
	new = ft_lstnew("rra");
	instructions
	rrotate(stacks->stack_a);
}

int	rrb(t_stacks *stacks, t_list **instructions)
{
	ft_printf("> R Rotate B");
	rrotate(stacks->stack_b);
}

int	rrr(t_stacks *stacks, t_list **instructions)
{
	ft_printf("> R Rotate A & B");
	rrotate(stacks->stack_a);
	rrotate(stacks->stack_b);
}
