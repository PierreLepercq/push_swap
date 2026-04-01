/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithms.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 17:25:15 by plepercq          #+#    #+#             */
/*   Updated: 2026/04/01 15:51:12 by plepercq         ###   ########.fr       */
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
# include "ps_utils.h"

void	test_algorithm(t_stacks *stacks);
void	turk_algorithm(t_stacks *stacks);

#endif