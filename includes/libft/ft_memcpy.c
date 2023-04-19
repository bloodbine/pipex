/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasztor <gpasztor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:11:13 by gpasztor          #+#    #+#             */
/*   Updated: 2022/11/14 14:20:05 by gpasztor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int			count;
	int			i;
	char		*destination;
	const char	*source;

	if (dst == 0 && src == 0)
		return (dst);
	i = 0;
	count = n;
	destination = (char *)dst;
	source = (const char *)src;
	while (count > 0)
	{
		destination[i] = source[i];
		i++;
		count--;
	}
	return (dst);
}
