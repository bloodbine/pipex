/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasztor <gpasztor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 13:31:45 by gpasztor          #+#    #+#             */
/*   Updated: 2022/11/17 14:34:21 by gpasztor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_count_delim(char const *s, char c)
{
	unsigned int	ci;
	unsigned int	count;

	ci = 0;
	count = 0;
	while (s[ci])
	{
		if (s[ci] != c && (s[ci + 1] == c || s[ci + 1] == '\0'))
			count++;
		ci++;
	}
	return (count);
}

static void	ft_free_all(char **parent)
{
	int	k;

	k = 0;
	while (parent[k])
	{
		free(parent[k]);
		k++;
	}
	free(parent);
}

static int	ft_assignation(char const *s, char c, char **parent, int k)
{
	int		i;
	int		j;

	i = 0;
	while (s[i] != '\0')
	{
		if (i == 0 || (s[i - 1] == c && s[i] != c))
			j = i;
		if (i > 0 && s[i] == c && s[i - 1] != c)
		{
			parent[k] = ft_substr(s, j, i - j);
			if (!parent[k])
				return (1);
			k++;
		}
		i++;
		if (s[i] == '\0' && s[i - 1] != c)
		{
			parent[k] = ft_substr(s, j, i - j);
			if (!parent[k])
				return (1);
		}
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char			**parent;
	unsigned int	delims;
	int				assign_status;

	if (!s)
		return (NULL);
	delims = ft_count_delim(s, c);
	parent = (char **)malloc((delims + 1) * sizeof(char *));
	if (!parent)
		return (NULL);
	assign_status = ft_assignation(s, c, parent, 0);
	if (!parent)
		return (NULL);
	if (assign_status)
	{
		ft_free_all(parent);
		return (NULL);
	}
	parent[delims] = NULL;
	return (parent);
}
