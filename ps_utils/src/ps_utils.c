/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 15:25:37 by plepercq          #+#    #+#             */
/*   Updated: 2026/04/04 15:27:19 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_utils.h"

void	moven(t_stacks *stacks, void (*move_func)(void *), int n)
{
	int	i;

	i = 0;
	while (i++ < n)
	{
		move_func(stacks);
	}
}
