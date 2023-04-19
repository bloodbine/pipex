/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasztor <gpasztor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 11:19:41 by gpasztor          #+#    #+#             */
/*   Updated: 2022/11/14 14:19:45 by gpasztor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strnlen(const char *s, size_t len)
{
	const char	*ptr;

	ptr = s;
	while (*ptr && len)
	{
		ptr++;
		len--;
	}
	return (ptr - s);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	maxlen;

	if (!s)
		return (NULL);
	maxlen = ft_strlen(s);
	if (maxlen < start)
		start = maxlen;
	s += start;
	len = ft_strnlen(s, len);
	substring = (char *)malloc((len + 1) * sizeof(char));
	if (!substring)
		return (NULL);
	ft_memcpy(substring, s, len);
	substring[len] = '\0';
	return (substring);
}
