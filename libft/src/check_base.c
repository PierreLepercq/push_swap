/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_base.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 18:14:51 by plepercq          #+#    #+#             */
/*   Updated: 2026/01/18 16:16:14 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_base(char *base)
{
	int	len;
	int	i;

	len = 0;
	while (base[len])
	{
		i = 1;
		while (base[len + i])
		{
			if (base[len] == base[len + i])
				return (0);
			i++;
		}
		if (base[len] == '+' || base[len] == '-')
			return (0);
		len++;
	}
	if (len < 2)
		return (0);
	return (1);
}
