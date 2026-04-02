/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithms.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 17:25:15 by plepercq          #+#    #+#             */
/*   Updated: 2026/04/02 16:56:23 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_ALGORITHMS_H
# define SORT_ALGORITHMS_H

# include "libft.h"
# include "ps_utils.h"
# include "stack.h"
# include <limits.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_moveset
{
	void		(*p)(void *);
	void		(*r)(void *);
	void		(*rr)(void *);
	void		(*s)(void *);
}				t_moveset;

typedef struct s_movesets
{
	t_moveset	*ms_a;
	t_moveset	*ms_b;
}				t_movesets;

void			test_algorithm(t_stacks *stacks);
void			turk_algorithm(t_stacks *stacks);

#endif