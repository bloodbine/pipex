/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasztor <gpasztor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 12:25:51 by gpasztor          #+#    #+#             */
/*   Updated: 2022/11/14 14:19:54 by gpasztor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*nstring;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	nstring = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!nstring)
		return (NULL);
	while (s1[i] != '\0')
	{
		nstring[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		nstring[i] = s2[j];
		i++;
		j++;
	}
	nstring[i] = '\0';
	return (nstring);
}
