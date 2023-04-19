/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasztor <gpasztor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:46:39 by gpasztor          #+#    #+#             */
/*   Updated: 2023/01/24 17:45:49 by gpasztor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen2(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr2(const char *s, int c)
{
	char	ch;

	if (!s)
		return (NULL);
	ch = (char)c;
	while (*s != ch && *s != '\0')
		s++;
	if (*s == ch)
		return ((char *)s);
	else
		return (NULL);
}

char	*ft_strdup2(const char *s1)
{
	char	*dst;
	int		i;

	i = 0;
	dst = malloc(ft_strlen2(s1) + 1);
	if (dst == NULL)
		return (NULL);
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_frstrjoin(char *rest, char *buff, int bytes)
{
	char	*newstring;
	size_t	i;
	size_t	j;

	if (!rest && bytes == 0)
		return (NULL);
	if (!rest)
		return (ft_strdup2(buff));
	newstring = malloc(ft_strlen2(rest) + ft_strlen2(buff) + 1);
	if (!newstring)
		return (NULL);
	i = -1;
	j = -1;
	while (rest[++i])
		newstring[i] = rest[i];
	while (buff[++j])
	{
		newstring[i] = buff[j];
		i++;
	}
	newstring[i] = '\0';
	return (free(rest), newstring);
}
