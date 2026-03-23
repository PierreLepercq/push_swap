/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithms.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 17:25:15 by plepercq          #+#    #+#             */
/*   Updated: 2026/03/23 15:49:35 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_ALGORITHMS_H
# define SORT_ALGORITHMS_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <limits.h>
# include "libft.h"
# include "stack.h"

void	test_algorithm(t_stack **a_stack, t_stack **b_stack);
void	turk_algorithm(t_stack **a_stack, t_stack **b_stack);

#endif