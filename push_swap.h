/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 15:53:42 by plepercq          #+#    #+#             */
/*   Updated: 2026/02/27 16:02:29 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>

typedef struct s_stack_node
{
	int					id;
	int					value;
	int					cost;
	
	struct s_stack_node	*prev;
	struct s_stack_node	*next;
}	t_stack_node

#endif