/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasztor <gpasztor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:46:36 by gpasztor          #+#    #+#             */
/*   Updated: 2022/12/07 16:07:35 by gpasztor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_get_line(char *rest)
{
	char	*line;
	int		i;

	if (!rest || !rest[0])
		return (NULL);
	i = 0;
	while (rest[i] && rest[i] != '\n')
		i++;
	if (ft_strchr(rest, '\n'))
		line = (char *)malloc((i + 2) * sizeof(char));
	else
		line = (char *)malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (rest[i] && rest[i] != '\n')
	{
		line[i] = rest[i];
		i++;
	}
	if (rest[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_refresh_rest(char *rest)
{
	char	*newrest;
	int		i;
	int		j;

	if (!rest[0])
		return (free(rest), NULL);
	i = 0;
	j = 0;
	while (rest[i] && rest[i] != '\n')
		i++;
	if ((ft_strlen(rest) - i + 1) <= 0)
		return (free(rest), NULL);
	if (rest[i] && !rest[++i])
		return (free(rest), NULL);
	newrest = (char *)malloc((ft_strlen(rest) - i + 1) * sizeof(char));
	while (rest[i] != '\0')
	{
		newrest[j] = rest[i];
		j++;
		i++;
	}
	newrest[j] = '\0';
	return (free(rest), newrest);
}

char	*get_next_line(int fd)
{
	static char	*rest[MAX_FD];
	char		*buff;
	char		*line;
	int			count;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!rest[fd])
		rest[fd] = NULL;
	count = 1;
	while (count > 0 && !ft_strchr(rest[fd], '\n'))
	{
		count = read(fd, buff, BUFFER_SIZE);
		if (count == -1)
			return (free(buff), free(rest[fd]), rest[fd] = NULL, NULL);
		buff[count] = '\0';
		rest[fd] = ft_frstrjoin(rest[fd], buff, count);
	}
	if (!rest[fd])
		return (free(buff), NULL);
	line = ft_get_line(rest[fd]);
	rest[fd] = ft_refresh_rest(rest[fd]);
	return (free(buff), line);
}
