/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 13:35:04 by plepercq          #+#    #+#             */
/*   Updated: 2025/11/20 18:46:27 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	lstaddmodified(t_list **lst, t_list *elem, void *(*f)(void *),
		void (*del)(void *))
{
	t_list	*new;
	void	*ncontent;

	ncontent = f(elem->content);
	new = ft_lstnew(ncontent);
	if (!new)
	{
		ft_lstclear(lst, del);
		del(ncontent);
		return ;
	}
	ft_lstadd_back(lst, new);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	int		i;
	t_list	*lst2;

	if (!lst)
		return (NULL);
	lst2 = NULL;
	i = 0;
	while (lst)
	{
		lstaddmodified(&lst2, lst, f, del);
		if (!lst2)
			break ;
		lst = lst->next;
	}
	return (lst2);
}
