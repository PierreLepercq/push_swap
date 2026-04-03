/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_moveset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 20:07:27 by plepercq          #+#    #+#             */
/*   Updated: 2026/04/03 20:09:08 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_utils.h"

t_moveset	*init_ms(
	void (*func_push)(void *),
	void (*func_rotate)(void *),
	void (*func_rrotate)(void *),
	void (*func_swap)(void *))
{
	t_moveset	*ms;

	ms = malloc(sizeof(t_moveset));
	if (!ms)
		return (NULL);
	ms->p = func_push;
	ms->r = func_rotate;
	ms->rr = func_rrotate;
	ms->s = func_swap;
}
