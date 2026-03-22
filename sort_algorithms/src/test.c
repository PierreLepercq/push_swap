/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 18:38:10 by plepercq          #+#    #+#             */
/*   Updated: 2026/03/22 18:38:27 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_algorithms.h"

void	test_algorithm(t_stack **a_stack, t_stack **b_stack)
{
	stack_print(a_stack, "stack A");
	stack_print(b_stack, "stack B");

	push(a_stack, b_stack);
	push(a_stack, b_stack);

	stack_print(a_stack, "stack A");
	stack_print(b_stack, "stack B");

	rotate(b_stack);

	stack_print(a_stack, "stack A");
	stack_print(b_stack, "stack B");

	rrotate(b_stack);

	stack_print(a_stack, "stack A");
	stack_print(b_stack, "stack B");

	swap(b_stack);

	stack_print(a_stack, "stack A");
	stack_print(b_stack, "stack B");

	push(b_stack, a_stack);
	push(b_stack, a_stack);

	stack_print(a_stack, "stack A");
	stack_print(b_stack, "stack B");
}