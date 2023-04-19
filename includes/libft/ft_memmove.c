/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasztor <gpasztor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:35:48 by gpasztor          #+#    #+#             */
/*   Updated: 2022/11/17 14:46:02 by gpasztor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*destination;
	unsigned char	*source;

	if (!dst && !src)
		return (dst);
	destination = (unsigned char *)dst;
	source = (unsigned char *)src;
	if (source < destination)
	{
		destination = destination + len - 1;
		source = source + len - 1;
		while (len--)
			*destination-- = *source--;
	}
	else if (source >= destination)
	{
		while (len--)
			*destination++ = *source++;
	}
	return (dst);
}
