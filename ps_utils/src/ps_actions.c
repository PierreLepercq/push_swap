/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 14:33:08 by plepercq          #+#    #+#             */
/*   Updated: 2026/04/01 15:37:43 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_utils.h"

t_list	*action_new(const char *str)
{
	t_list	*node;
	char	*s;

	s = malloc(sizeof(char) * ft_strlen(str));
	if (s == NULL)
		return (NULL);
	ft_strlcpy(s, str, ft_strlen(str));
	node = ft_lstnew(s);
	return (node);
}

void	action_add_back(t_list **lst, t_list *node)
{
	if (node == NULL)
		return (NULL);
	if (*lst == NULL)
		*lst = node;
	else
		ft_lstadd_back(lst, node);
}

void	action_insert(t_list *prev, t_list *node)
{
	t_list	*tmp;

	if (node == NULL || prev == NULL)
		return (0);
	tmp = prev->next;
	prev->next = node;
	node->next = tmp;
}

void	action_delone(t_list **lst, t_list *node)
{
	t_list	*prev;

	prev = *lst;
	while (prev->next != node && prev->next != NULL)
		prev = prev->next;
	if (prev->next == node)
			prev->next = node->next;
	ft_lstdelone(node, free);
}
