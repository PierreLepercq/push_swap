/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 15:53:42 by plepercq          #+#    #+#             */
/*   Updated: 2026/04/06 10:55:47 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ps_utils.h"
# include "sort_algorithms.h"
# include "stack.h"
# include <limits.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

int		check_atoi(const char *s);
int		*strs_to_ints(char **strs, int len);
int		*confo_inputs(char **inputs, int *len);
bool	has_duplicates(int *values, int len);

#endif