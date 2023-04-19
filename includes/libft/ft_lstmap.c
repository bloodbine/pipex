/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasztor <gpasztor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:36:40 by gpasztor          #+#    #+#             */
/*   Updated: 2022/11/14 14:20:10 by gpasztor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nlst;
	t_list	*nnode;

	if (!lst || !f)
		return (NULL);
	nnode = ft_lstnew(f(lst->content));
	if (!nnode)
		return (NULL);
	nlst = nnode;
	lst = lst->next;
	while (lst)
	{
		nnode = ft_lstnew(f(lst->content));
		if (!nnode)
		{
			ft_lstclear(&nlst, del);
			return (NULL);
		}
		lst = lst->next;
		ft_lstadd_back(&nlst, nnode);
	}
	return (nlst);
}
