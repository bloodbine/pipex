/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasztor <gpasztor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:42:04 by gpasztor          #+#    #+#             */
/*   Updated: 2023/01/24 17:44:33 by gpasztor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

size_t	ft_strlen2(const char *s);
char	*ft_strchr2(const char *s, int c);
char	*ft_strdup2(const char *s1);
char	*ft_frstrjoin(char *rest, char *buff, int bytes);
char	*ft_get_line(char *rest);
char	*ft_refresh_rest(char *rest);
char	*get_next_line(int fd);

#endif
