/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasztor <gpasztor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:36:22 by gpasztor          #+#    #+#             */
/*   Updated: 2022/11/14 14:20:16 by gpasztor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*to_free;

	if (!lst)
		return ;
	while (*lst)
	{
		if ((*lst)->content)
			del((*lst)->content);
		to_free = *lst;
		*lst = (*lst)->next;
		free(to_free);
	}
	*lst = NULL;
}
