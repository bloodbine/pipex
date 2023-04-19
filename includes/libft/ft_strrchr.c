/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasztor <gpasztor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 09:39:37 by gpasztor          #+#    #+#             */
/*   Updated: 2022/11/14 14:19:47 by gpasztor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	ch;
	int		i;

	i = ft_strlen(s);
	ch = (char)c;
	while (i > 0)
	{
		if (s[i] == ch)
			return ((char *)(s + i));
		i--;
	}
	if (s[i] == ch)
		return ((char *)(s + i));
	return (0);
}
