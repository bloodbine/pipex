/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasztor <gpasztor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 11:33:42 by gpasztor          #+#    #+#             */
/*   Updated: 2023/04/26 11:58:39 by gpasztor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include "libft/libft.h"

void	error(int exitcode);
char	*find_path(char *command, char **envp);

#endif