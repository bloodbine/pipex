/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasztor <gpasztor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 16:30:16 by gpasztor          #+#    #+#             */
/*   Updated: 2022/11/17 14:43:54 by gpasztor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	tofind;
	unsigned char	*string;

	tofind = (unsigned char)c;
	string = (unsigned char *)s;
	while (n--)
	{
		if (*string++ == tofind)
			return (string - 1);
	}
	return (NULL);
}
