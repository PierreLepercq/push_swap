/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 15:53:42 by plepercq          #+#    #+#             */
/*   Updated: 2026/04/05 18:01:31 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <limits.h>
# include <stdbool.h>
# include "libft.h"
# include "stack.h"
# include "ps_utils.h"
# include "sort_algorithms.h"

int	    check_atoi(const char *s);
int	    *strs_to_ints(char **strs, int len);
int	    *confo_inputs(char **inputs, int *len);
bool	has_duplicates(int *values, int len);

#endif